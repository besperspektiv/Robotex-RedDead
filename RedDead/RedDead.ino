#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include <SharpDistSensor.h>
#include "GyverPID.h"
#include <SoftwareSerial.h>


#define rxPin 10
#define txPin 11
#define INTERRUPT_PIN 2
#define OUTPUT_READABLE_YAWPITCHROLL

SoftwareSerial mySerial(rxPin, txPin); // RX, TX
MPU6050 mpu;


// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];  
float y;

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}

// Window size of the median filter (odd number, 1 = no filtering)
const byte medianFilterWindowSize = 4;
bool troble_rotation;  //0 = right   1 = left
byte SpeedAA;
byte SpeedBB;
unsigned long timing;
unsigned long overtaking_timing;
unsigned long Left_Sensor_On_Time;
unsigned long Front_sensor_On_Time;
int interval = 1000;                          //время задержки перед действием


int kp = 2.5;
int ki = 0.01;
int kd = 0.5;

GyverPID all_motors_pid(kp, ki, kd, 20); // П, И, Д,

//=======Distance Sensors========

const byte sensor_front_Pin = A3;
const byte sensor_right_Pin = A2;
const byte sensor_left_Pin = A6;

SharpDistSensor sensor_right(sensor_right_Pin, medianFilterWindowSize);
SharpDistSensor sensor_left(sensor_left_Pin, medianFilterWindowSize);

//=======Motors========                       //      перед
#define AA_PWM_Motor  6                       //        ↑
#define AA_1_Motor  4                         //    █[][][]█
#define AA_2_Motor  5                         //     [[][][]]
                                              //     [[][][]]      чёрные квадраты
#define BB_PWM_Motor  3                       // AA  [[][][]] BB   это колёса
#define BB_1_Motor  8                         //     [[][][]]
#define BB_2_Motor  9                         //    █[][][]█

bool flag = 0;
bool turn = 0;    //1 = right   0 = left
int police_go = 0;
bool Start_flag = 0;
bool start_without_delay = 0;
byte R = A2, G = A1, B = A3;
bool overtaking = 0;
int distance_front;
unsigned int distance_right;
unsigned int distance_left;

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////SETUP///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
void setup() {
  MPU6050_Init();
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  pinMode(sensor_front_Pin, INPUT);
  pinMode(sensor_right_Pin, INPUT);
  pinMode(sensor_left_Pin, INPUT);

  pinMode(A0, OUTPUT);
  digitalWrite(A0, LOW);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(115200);

  //*****************************************************************
  pinMode(AA_PWM_Motor, OUTPUT);
  pinMode(AA_1_Motor, OUTPUT);
  pinMode(AA_2_Motor, OUTPUT);

  pinMode(BB_PWM_Motor, OUTPUT);
  pinMode(BB_1_Motor, OUTPUT);
  pinMode(BB_2_Motor, OUTPUT);
  ////////////////////PID///////////////

  all_motors_pid.setpoint = 0;
  all_motors_pid.setDirection(REVERSE); // направление регулирования (NORMAL/REVERSE). ПО УМОЛЧАНИЮ СТОИТ NORMAL
  all_motors_pid.setLimits(0, 255);    // пределы (ставим для 8 битного ШИМ). ПО УМОЛЧАНИЮ СТОЯТ 0 И 255
  
  //////////////////////////////////////
  
  Serial.println("go");
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////LOOP////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
void loop() {
  Mooving_program();
  MPU6050_Read();
  Sensors_Read();
  Serial_Print();
}

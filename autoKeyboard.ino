#include <Wire.h>                     // ライブラリのインクルード
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm0 = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);  // PCA9685のI2Cアドレスを指定

#define SERVOMIN 500    // 最小パルス幅(μs)
#define SERVOMAX 2400   // 最大パルス幅(μs)


int Servo_pin0 = 0;      // サーボ接続ピンを0番に
int Servo_pin1 = 1;
int Servo_pin2 = 2;
int Servo_pin3 = 3;
int Servo_pin4 = 4;
int Servo_pin5 = 5;
int Servo_pin6 = 6;
int Servo_pin7 = 7;
int Servo_pin8 = 8;
int Servo_pin9 = 9;
int off, leftON, rightON;

char data, prePin;
Adafruit_PWMServoDriver preBoard;

void setup() {
  off = map(90 ,0, 180, SERVOMIN, SERVOMAX);  // 角度(0~180)をパルス幅(500~2400μs)に変換
  leftON = map(180,0, 180, SERVOMIN, SERVOMAX);
  rightON = map(0,0, 180, SERVOMIN, SERVOMAX);   
   
  pwm0.begin();         // 初期設定
  pwm0.setPWMFreq(50); // PWM周期を50Hzに設定
  pwm1.begin();         // 初期設定
  pwm1.setPWMFreq(50); // PWM周期を50Hzに設定
  Serial.begin(9600);
  delay(1000);
}

void loop()
{
  if ( Serial.available()  > 0 ) {   // 受信データがあるか？
    data = Serial.read();            // 1文字だけ読み込む
    
    switch(data) { //?
      case 0x3f:
        preBoard.writeMicroseconds(prePin, off);
        break;
      case 0x41: //a
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin1, rightON);
        preBoard = pwm0;
        prePin = Servo_pin1;
        break;
      case 0x42:  //b
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin4, rightON);
        preBoard = pwm0;
        prePin = Servo_pin4;
        break;
      case 0x43: //c
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin2, rightON);
        preBoard = pwm0;
        prePin = Servo_pin2;
        break;
      case 0x44: //d
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin5, leftON);
        preBoard = pwm1;
        prePin = Servo_pin5;
        break;
      case 0x45:  //e
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin6, leftON);
        preBoard = pwm1;
        prePin = Servo_pin6;
        break;
      case 0x46:  //f
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin5, rightON);
        preBoard = pwm1;
        prePin = Servo_pin5;
        break;
      case 0x47:  //g
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin3, rightON);
        preBoard = pwm0;
        prePin = Servo_pin3;
        break;
      case 0x48:  //h
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin3, leftON);
        preBoard = pwm0;
        prePin = Servo_pin3;
        break;
      case 0x49: //i
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin3, rightON);
        preBoard = pwm1;
        prePin = Servo_pin3;
        break;
      case 0x4a:  //j
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin5, leftON);
        preBoard = pwm0;
        prePin = Servo_pin5;
        break;
      case 0x4b:  //k
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin6, rightON);
        preBoard = pwm0;
        prePin = Servo_pin6;
        break;
      case 0x4c: //l
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin6, leftON);
        preBoard = pwm0;
        prePin = Servo_pin6;
        break;
      case 0x4d:  //m
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin5, rightON);
        preBoard = pwm0;
        prePin = Servo_pin5;
        break;
      case 0x4e:  //n
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin4, leftON);
        preBoard = pwm0;
        prePin = Servo_pin4;
        break;
      case 0x4f:  //o
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin2, leftON);
        preBoard = pwm1;
        prePin = Servo_pin2;
        break;
      case 0x50:  //p
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin2, rightON);
        preBoard = pwm1;
        prePin = Servo_pin2;
        break;
      case 0x51: //q
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin7, leftON);
        preBoard = pwm1;
        prePin = Servo_pin7;
        break;
      case 0x52: //r
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin6, rightON);
        preBoard = pwm1;
        prePin = Servo_pin6;
        break;
      case 0x53:  //s
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin1, leftON);
        preBoard = pwm0;
        prePin = Servo_pin1;
        break;
      case 0x54:  //t
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin4, leftON);
        preBoard = pwm1;
        prePin = Servo_pin4;
        break;
      case 0x55:  //u
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin3, leftON);
        preBoard = pwm1;
        prePin = Servo_pin3;
        break;
      case 0x56:  //v
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin2, leftON);
        preBoard = pwm0;
        prePin = Servo_pin2;
        break;
      case 0x57:  //w
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin7, rightON);
        preBoard = pwm1;
        prePin = Servo_pin7;
        break;
      case 0x58:  //x
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin0, leftON);
        preBoard = pwm0;
        prePin = Servo_pin0;
        break;
      case 0x59:  //y
        preBoard.writeMicroseconds(prePin, off);
        pwm1.writeMicroseconds(Servo_pin4, rightON);
        preBoard = pwm1;
        prePin = Servo_pin4;
        break;
      case 0x5a:  //z
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin0, rightON);
        preBoard = pwm0;
        prePin = Servo_pin0;
        break;
      case 0x32:
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin0, leftON);
        preBoard = pwm0;
        prePin = Servo_pin0;
        break;
      case 0x31:
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin0, leftON);
        preBoard = pwm0;
        prePin = Servo_pin0;
        break;
      case 0x30:
        preBoard.writeMicroseconds(prePin, off);
        pwm0.writeMicroseconds(Servo_pin0, leftON);
        preBoard = pwm0;
        prePin = Servo_pin0;
        break;
    }
    delay(100);
  } 
}

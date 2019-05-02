#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int one = 0;
int two = 0;
int five = 0;
int ten = 0;
int all = one+two+five+ten;

char KEYS[16] = {
  '1', '2', '3', 'A',
  '4', '5', '6', 'B',
  '7', '8', '9', 'C',
  '*', '0', '#', 'D'
};

const byte interruptPin = 3;//กำหนด Interrupt pin
volatile byte keyValue=0;
volatile bool printState = false;
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(interruptPin), keypadRead,FALLING);
  Serial.begin(9600);

  
  servo.attach(6);
  servo2.attach(9);
  servo3.attach(10);
  servo4.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = KEYS[keyvalue];
  println(key);
}
void keypadRead(){
  keyValue=0;
printState=true;//จะมีหรือไม่ขึ้นอยู่กับโปรแกรม
 keyValue=(-digitalRead(5))&1;    //กำหนดindex จากข้อมูลของIC
 keyValue+=((-digitalRead(13))&2);
 keyValue+=((-digitalRead(12))&4);
 keyValue+=((-digitalRead(8))&8);
}

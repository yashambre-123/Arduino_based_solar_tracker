#include <Servo.h>
Servo myservo;
int pos=90;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(3);
  pinMode(3,OUTPUT);
  myservo.write(90);
}

void loop() {
//  // put your main code here, to run repeatedly:
  int ldr_left=analogRead(A0);
  int ldr_right=analogRead(A1);
  Serial.println("ldr_left:");
  Serial.println(ldr_left);
  Serial.println("ldr_right:");
  Serial.println(ldr_right);
  if (ldr_left<500){
    pos=--pos;
  }
  else if (ldr_right<600){
    pos=++pos;
  }
  myservo.write(pos);
}

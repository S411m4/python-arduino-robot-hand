#include <Servo.h>

#define thumbPin 7
#define indexPin 10
#define middlePin 9
#define ringPin 6
#define pinkyPin 3


Servo servoThumb;
Servo servoIndex;
Servo servoMiddle;
Servo servoRing;
Servo servoPinky;


void setup() {
   servoThumb.attach(thumbPin);
  servoIndex.attach(indexPin);
  servoMiddle.attach(middlePin);
  servoRing.attach(ringPin);
  servoPinky.attach(pinkyPin);
}

void loop() {
  servoThumb.write(
    180);
  servoIndex.write(180);
  servoMiddle.write(180);
  servoRing.write(180);
  servoPinky.write(0);
  delay(1000);
  servoThumb.write(0);
  servoIndex.write(0);
  servoMiddle.write(0);
  servoRing.write(0);
  servoPinky.write(0);
  delay(1000);
  

}

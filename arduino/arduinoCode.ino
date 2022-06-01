#include <Servo.h>

#define numOfValsRec 5
#define digitsPerValRec 1

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


int valsRec[numOfValsRec];

//$00000
int stringLength = numOfValsRec * digitsPerValRec + 1;
int counter = 0;
bool counterStart = false;
String recievedString;

void setup() {
  Serial.begin(9600);
  Serial.print("Test");
  servoThumb.attach(thumbPin);
  servoIndex.attach(indexPin);
  servoMiddle.attach(middlePin);
  servoRing.attach(ringPin);
  servoPinky.attach(pinkyPin);


 servoThumb.write(180);
  servoIndex.write(180);
  servoMiddle.write(180);
  servoRing.write(180);
  servoPinky.write(180);
  delay(1000);
  servoThumb.write(0);
  servoIndex.write(0);
  servoMiddle.write(0);
  servoRing.write(0);
  servoPinky.write(0);
  delay(1000);
  
}

void loop() {
  receiveData();

   if(valsRec[0] == 1){servoThumb.write(0);}else{servoThumb.write(180);}
   if(valsRec[1] == 1){servoIndex.write(0);}else{servoIndex.write(180);}
   if(valsRec[2] == 1){servoMiddle.write(0);}else{servoMiddle.write(180);}
   if(valsRec[3] == 1){servoRing.write(0);}else{servoRing.write(180);}
   if(valsRec[4] == 1){servoPinky.write(180);}else{servoPinky.write(0);}
}


void receiveData(){
  while(Serial.available())
  {
    char c = Serial.read();

    if(c == '$')
  {
    counterStart = true;
    }
    if(counterStart)
    {
      if(counter < stringLength)
      {
        recievedString = String(recievedString + c);
        counter++;
      }

      if(counter >= stringLength)
      {Serial.print("fingers = ");
        Serial.println(recievedString);
        //$00000
        for(int i = 0; i <numOfValsRec; i++)
        {
          int num = (i * digitsPerValRec) + 1;
          valsRec[i] = recievedString.substring(num, num+digitsPerValRec).toInt();
        }
        recievedString = "";
        counter = 0;
        counterStart = false;
      }
    }
  }
}

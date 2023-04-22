// C++ code
//
#include<Servo.h>
Servo Myservo;
const int LDRPin=A0;
#define MLa 2
#define MLb 3
#define MRa 4
#define MRb 5

int pos=0;


void setup()
{
  Serial.begin(9600);
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
  pinMode(LDRPin,INPUT);
  Myservo.attach(10);
}

void loop()
{
  int LDRstatusF,LDRstatusL,LDRstatusR;
  LDRstatusR=analogRead(LDRPin);
  Myservo.write(90);
  delay(2000);
  LDRstatusF=analogRead(LDRPin);
  Myservo.write(180);
  delay(2000);
  LDRstatusL=analogRead(LDRPin);
  Myservo.write(0);
  delay(2000);
  if (LDRstatusF > LDRstatusR && LDRstatusF > LDRstatusL){
  	// Move forward
    digitalWrite(MRb, HIGH);
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, HIGH);                                
    digitalWrite(MLa, LOW);
    delay(2000);
  }
  else if(LDRstatusF < LDRstatusR || LDRstatusF < LDRstatusL){
    if (LDRstatusR > LDRstatusL){
    	//MOve Right
    	digitalWrite(MRb, LOW); 
    	digitalWrite(MRa, LOW);   
    	digitalWrite(MLa, HIGH);                                 
    	digitalWrite(MLb, LOW);
        delay(2000);
    }
    else{
    	//Move left
    	digitalWrite(MRb, HIGH);      
    	digitalWrite(MRa, LOW);   
    	digitalWrite(MLa, LOW);                                 
    	digitalWrite(MLb, LOW);
		delay(2000);
    }
  }
  else{
    //Stop
  	digitalWrite(MRb, LOW); 
   	digitalWrite(MRa, LOW);   
   	digitalWrite(MLa, LOW);                                 
   	digitalWrite(MLb, LOW); 
    delay(2000);
  }
}
#include <Wire.h>
int myRelay=13;
volatile byte relayState=LOW;
int myCount=1;
const int relayPin=13;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
    Serial.println("Connected");
  pinMode(myRelay, OUTPUT);
  digitalWrite(myRelay, LOW);
  relayState=LOW;
  Serial.println("Relay Off");
}

void loop() {
  // put your main code here, to run repeatedly:
  float myTemp=101;
  Serial.print(myCount);
  Serial.print("Temp: ");
  Serial.print(myTemp, 1);
  Serial.println("*F: ");
  if(myTemp>100 && relayState==LOW){
    pullRelayHigh();
    delay(2000);
    pullRelayLow();
  }
  myCount=myCount+1;
  delay(5000);
}

void pullRelayHigh(){
  if(relayState!=HIGH){
    digitalWrite(myRelay, HIGH);
    relayState=HIGH;
    Serial.println("Relay On");
  }
}

void pullRelayLow(){
  if(relayState!=LOW){
    digitalWrite(myRelay, LOW);
    relayState=LOW;
    Serial.println("Relay Off");
  }
}
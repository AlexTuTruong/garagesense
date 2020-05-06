//GarageSense
//Alex Tu
#include <LowPower.h>

//Pin setup
//Relay
const int relayVcc = 12;
const int relaySignal = 11;

#define ON "on"
#define OFF "off"

//Limit switch
const int limitSw = 6;

void setup() {
  //Relay
  pinMode(relayVcc, OUTPUT);
  pinMode(relaySignal, OUTPUT);

  //Limit Switch
  pinMode(limitSw, INPUT);
  
  //Serial monitor(DEBUG)
  Serial.begin(9600);
}


void loop() {
  //Limit switch state read
  if (digitalRead(limitSw) == HIGH){
//    Serial.println("OPEN"); //DEBUG
    relay(ON);
  }
  else{
    relay(OFF);
//    Serial.println("CLOSED"); //DEBUG
  }
  //Delay
  delay(50);
  LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF); 
}


//FUNCTIONS
//Relay Functions
void relay(String onOff){

  if (onOff == ON){
    digitalWrite(relayVcc, HIGH);
    delay(250);
    digitalWrite(relaySignal, HIGH);
  }
  else{
    digitalWrite(relayVcc, LOW);
    delay(250);
    digitalWrite(relaySignal, LOW);
  }

}
//test
#include <LowPower.h>

//Pin setup
//Relay
const int relayVcc = 12;
const int relaySignal = 11;

#define ON "on"
#define OFF "off"

//UltraSonic Sensor
const int ultraTrig = 7;
const int ultraEcho = 6;

void setup() {
  //Relay
  pinMode(relayVcc, OUTPUT);
  pinMode(relaySignal, OUTPUT);

  //UltraSonic Sensor
  pinMode(ultraTrig, OUTPUT);
  pinMode(ultraEcho, INPUT);
  
  //Serial monitor(DEBUG)
  Serial.begin(9600);
}

void loop() {
  //Variables
  int avgs[] = {0, 0}, avg = 0;

  //Pulse 3x3 times for average distance
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
       delay(50);
       avgs[i] += sonicPulse();
       delay(50);
    }
    //Set averages
    avgs[i] /= 2;
    //Print readings(DEBUG)
    Serial.print(avgs[i]);
    Serial.println();
    avg += avgs[i];
  }

  //Get average of averages
  avg /= 2;

  //Check if distance is less than 10cm
  if (avg <= 10){
    relay(OFF);
  }
  else{
    relay(ON);
  }
  
  //print distance (DEBUG)
  Serial.print(avg);
  Serial.print("cm");
  Serial.println();


  //Delay
  delay(50);
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF); 
}

//FUNCTIONS

//Ultrasonic sensor return in cm
long sonicPulse(){
  //Clear Pin
  digitalWrite(ultraTrig, LOW);
  delayMicroseconds(2);

  //Pulse
  digitalWrite(ultraTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraTrig, LOW);

  //Return distance in cm
  return pulseIn(ultraEcho, HIGH) / 29 / 2;
}

void relay(String onOff){
  if (onOff == ON){
    digitalWrite(relayVcc, HIGH);
    digitalWrite(relaySignal, HIGH);
  }
  else{
    digitalWrite(relayVcc, LOW);
    digitalWrite(relaySignal, LOW);
  }
}

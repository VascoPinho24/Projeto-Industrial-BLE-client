#include <Arduino.h>

const int analogInPin = 1;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;  // value read from the pot
float voltage = 0;  // voltage from the pot
int outputValue = 0;  // value output to the PWM (analog out)
float pot_voltage = 0;

float pot_value(float analogPin);

void setup() {
  Serial.begin(115200);
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  // read the analog in value:
  pot_voltage = pot_value(analogInPin);
  Serial.print(pot_voltage);
  Serial.print(" V\n");
  // wait 20 milliseconds before the next loop for the analog-to-digital
  
  delay(20);
}

float pot_value(float analogPin){
  int value = analogRead(analogPin);
  float voltage = value*3.3/4095;
  return voltage;
}
#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;
int led = 13;
int timeOn = 0;
float prevAZ = 0.5;

void setup()
{
  accelemeter.init();  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop()
{
  int8_t x;
  int8_t y;
  int8_t z;
  float ax,ay,az;
  accelemeter.getXYZ(&x,&y,&z);
  
  Serial.print("x = ");
    Serial.println(x); 
    Serial.print("y = ");
    Serial.println(y);   
    Serial.print("z = ");
    Serial.println(z);
    
  
  accelemeter.getAcceleration(&ax,&ay,&az);
    Serial.println("accleration of X/Y/Z: ");
  Serial.print(ax);
  Serial.println(" g");
  Serial.print(ay);
  Serial.println(" g");
  Serial.print(az);
  Serial.println(" g");
  Serial.println("***********");
  
  if (prevAZ -az > 0.1 && z < 18){
    digitalWrite(led, HIGH);
    timeOn++; 
  }
  else {
    digitalWrite(led, LOW);
  }

  prevAZ = az;
  delay(250);
 
}

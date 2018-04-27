#include "VU_ADJTIMER.h"
VU_ADJTIMER led;
void setup()
{
  
  Serial.begin(9600);
  led.set(1000,test);
  led.start();
  
  
 
}
void loop()
{
 Serial.println("ne olacak");
 delay(1000);
 
}

void test()
{
  Serial.println("hadilanoldu");
}
void test2()
{
  Serial.println("test");
}


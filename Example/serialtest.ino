#include "/VU_ADJTIMER.h"
VU_ADJTIMER serial;
void setup()
{
  Serial.begin(9600);
  serial.set(1000,test);
  serial.start();
  
}
void loop()
{
 Serial.println("work with loop");
 delay(1000);
 
}
void test()
{
  Serial.println("work with isr");
}



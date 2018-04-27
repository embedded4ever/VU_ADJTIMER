#include "VU_ADJTIMER.h"
void (*func)();
volatile unsigned int timercount;
volatile uint8_t  countcallfunc;
volatile unsigned int howtotaloverflow;
int happenedprevious=0;
int _times=1;
//#define DEBUG
 VU_ADJTIMER :: VU_ADJTIMER()
{
 }
void VU_ADJTIMER :: set(float duration , void (*f)())
{
  timercount=0;
  howtotaloverflow=(int)(duration/32.768);
  #ifdef DEBUG
  Serial.println(howtotaloverflow);
  #endif
  func=f;
  _times=0;
  
}
void VU_ADJTIMER :: set ( float duration , int times , void (*f)())
{
  howtotaloverflow=(int)(duration/32.768);
  _times=times;
  
  func=f;
}
void VU_ADJTIMER :: stop()
{
  TIMSK1 &= ~(1<<TOIE1);
}
void VU_ADJTIMER :: start()
{   
    TCCR1A = 0;
    TCCR1B = 0;
    TCCR1B |= (1 << CS11);
    TCNT1 = timercount;
    TIMSK1 |= (1 << TOIE1);
    
}
ISR(TIMER1_OVF_vect)
{ 
  countcallfunc++;
  
 if(countcallfunc >= howtotaloverflow  ) 
 { 
  boolean work;
  if(_times==0) {  work=true;}
  else { work =false; }
  if(_times &&  work==false) {
   _times--;
  happenedprevious=1; 
  TCNT1=timercount;
  countcallfunc=0;  
  (*func)(); 
  
  }
  else 
  {
  if(happenedprevious) void stop();
 
  else {
  TCNT1=timercount;
  countcallfunc=0;  
  (*func)();  }
 
  }
 }
    }




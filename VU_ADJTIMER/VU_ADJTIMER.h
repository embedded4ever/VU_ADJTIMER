#ifndef VU_ADJTIMER_H
#define VU_ADJTIMER_H
#include <avr/interrupt.h>
#include <avr/io.h>
#include "Arduino.h"


class VU_ADJTIMER
{
  public:
  
  VU_ADJTIMER();
  void set(float duration , void (*f)());
  void set(float duration, int times , void(*f)());
  void start();
  void stop();
};
#endif

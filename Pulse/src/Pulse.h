#ifndef _PULSE__H_
#define _PULSE__H_

#include <OneShot.h>

// Implement class to generate a single active-high pulse on a
// digital output pin.  Useful for flashing an LED, especially
// the one built into most Arduino-class boards, usually on pin 13.
// Active-high is used because that's what the pin 13 LED requires
// to turn on.
class Pulse
{
private:
  OneShot    m_os;     // one-shot to set on time
  const byte m_pin;    // digital output pin to be pulsed
  
public:
  Pulse(const byte pin, const unsigned int dly);
  virtual bool update();
  void trigger();
};

#endif


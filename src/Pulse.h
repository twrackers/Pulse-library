#ifndef _PULSE__H_
#define _PULSE__H_

#include <OneShot.h>

// Implement class to generate a single pulse, active-high or
// active-low, on a digital output pin.  Useful for flashing an LED,
// especially the LED_BUILTIN which exists on most Arduino-class boards
// (usually on pin 13).
//
// Dependencies
//   Pulse
//   +--uses--> OneShot
//              +--isa--> StateMachine
class Pulse
{
private:
  OneShot    m_os;          // one-shot to set on-time
  const byte m_pin;         // digital output pin to be pulsed
  const bool m_activeLevel; // true for active high output,
                            // false for active low output
  
public:
  // Constructor
  // @param pin digital output pin to be pulsed
  // @param active specify active LOW or HIGH pulse
  // @param dly length of pulse in milliseconds
  // @param retriggerable true if pulse can be retriggered
  Pulse(
    const byte pin,                   // digital output pin
    const byte active,                // active LOW or HIGH
    const unsigned long dly,          // pulse length in milliseconds
    const bool retriggerable = true   // retriggerable
  );
  
  // Check if it's time to update this object's state.
  // @return true if update of state occurred, false otherwise
  virtual bool update();
  
  // Trigger the pulse.
  void trigger();
};

#endif


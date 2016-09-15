#include "Pulse.h"

Pulse::Pulse(const byte pin, const unsigned int dly) :
  m_os(OneShot(dly)), m_pin(pin)
{
  // Set pin to output mode.
  pinMode(m_pin, OUTPUT);
}

bool Pulse::update()
{
  // If it's update time...
  if (m_os.update()) {
    // ... set the output pin to match the state of
    // the one-shot.
    digitalWrite(m_pin, m_os.isTriggered() ? HIGH : LOW);
    return true;
  }
  return false;
}

void Pulse::trigger()
{
  // Trigger the embedded one-shot.
  m_os.trigger();
}


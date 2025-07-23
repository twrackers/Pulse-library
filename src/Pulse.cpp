#include "Pulse.h"

Pulse::Pulse(
  const byte pin, 
  const byte active,
  const unsigned int dly
) : m_os(OneShot(dly, false)), m_pin(pin), m_activeLevel(active != LOW)
{
  // Set pin to output mode.
  pinMode(m_pin, OUTPUT);
  // Set pin to inactive level.
  digitalWrite(m_pin, (m_activeLevel == LOW ? HIGH : LOW));
}

Pulse::Pulse(
  const byte pin, 
  const unsigned int dly
) : Pulse(pin, HIGH, dly)
{
}

bool Pulse::update()
{
  // If it's update time...
  if (m_os.update()) {
    // ... set the output pin to match the state of the one-shot,
    // inverted if this object's active level is ACTIVE LOW
    // (m_activeLevel == false).
    digitalWrite(m_pin, ((m_os.isTriggered() ^ !m_activeLevel) ? HIGH : LOW));
    return true;
  }
  return false;
}

void Pulse::trigger()
{
  // Trigger the embedded one-shot.
  m_os.trigger();
}


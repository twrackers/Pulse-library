#include <Pulse.h>
#include <StateMachine.h>

Pulse pulse(13, LOW, 100);
StateMachine pace(1000, true);

void setup()
{
}

void loop()
{
  if (pace.update()) {
    pulse.trigger();
  }
  pulse.update();
}

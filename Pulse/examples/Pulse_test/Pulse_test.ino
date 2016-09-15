#include <Pulse.h>
#include <StateMachine.h>

Pulse pulse(13, 250);
StateMachine pace(1000, true);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  if (pace.update()) {
    pulse.trigger();
  }
  pulse.update();
}

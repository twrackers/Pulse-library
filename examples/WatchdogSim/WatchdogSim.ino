// This sketch mimics the action of a watchdog timer.
//
// A hardware watchdog timer is an electronic timer that is used to
// detect and recover from computer malfunctions. During normal operation,
// the computer regularly resets the watchdog timer to prevent it from
// elapsing, or "timing out". If, due to a hardware fault or program error,
// the computer fails to reset the watchdog, the timer will elapse and
// generate a timeout signal. The timeout signal is used to initiate
// corrective action or actions. The corrective actions typically include
// placing the computer system in a safe state and restoring normal system
// operation.
//
// In this sketch, a Pulse object simulates the watchdog timer.  The Pulse
// object contains an OneShot object in retriggerable mode.  A OneShot object
// is in an off state until it is triggered.  Once triggered, the OneShot
// goes to an on tate for a preset time period, then returns to its off state.
// If it is triggered again while already switched on, the timer gets reset
// back to zero, extending the on time.  As long as the OneShot keeps getting
// triggered before it times out, it will remain on.
//
// The Pulse object has an assigned GPIO pin, and a OneShot which has an on
// state of either HIGH or LOW.  In this sketch, the Pulse is tied to the
// onboard LED, with LOW (LED off) as the Pulse's on state.  As long as the
// Pulse is triggered frequently enough (within 200 msec of the previous
// trigger), the LED will remain off.  If the Pulse times out because a
// trigger did not occur in time, the LED will turn on until a trigger
// eventually happens.

#include <Arduino.h>
#include <StateMachine.h>
#include <Pulse.h>

// Random number generator will be sampled at 100 Hz (every 10 msec).
StateMachine pacer(10, true);

// When flash is triggered, it will turn off the LED for 200 msec.
// The flash is retriggerable, so the LED will remain off as long as
// triggers happen fast enough.
Pulse flash(LED_BUILTIN, LOW, 200);

void setup() {
  // No setup required.
}

void loop() {
  
  // Update the state of flash on each loop.  This is the point when
  // a trigger can be acted upon, or a timeout can occur.
  flash.update();
  
  // Is it time to update the pacer?
  // If so, does the random number generator return 0?
  // It will do so on the average 10% of the time.
  // The Pulse "watchdog" will time out, turning on the LED, if
  // 200 msec (20 samples at 10 msec per) passes without the
  // random number generator returning a zero.
  if (pacer.update() && (random(10) == 0)) {
    // (Re)trigger the flash, so the LED will switch off
    // or remain off the next time the flash is updated.
    flash.trigger();
  }
  
}

# Pulse #

The `Pulse` class uses the `OneShot` class ([https://github.com/twrackers/OneShot-library](https://github.com/twrackers/OneShot-library)), which is itself derived from the `StateMachine` class ([https://github.com/twrackers/StateMachine-library](https://github.com/twrackers/StateMachine-library)).  In other words, a *Pulse* object ***contains*** a *OneShot* object, while the *OneShot* ***is a*** *StateMachine* object. 

A *Pulse* object will create a rising or falling pulse of a fixed duration on one of the GPIO pins when it is triggered.  Like the *OneShot* class, a *Pulse* object is *retriggerable*, which means if it is triggered again before a pulse completes, the pulse timing will restart, extending the pulse.

## Examples ##

Because a *Pulse* object contains a *OneShot*, it can act as a [*watchdog* timer](https://en.wikipedia.org/wiki/Watchdog_timer) with a GPIO pin in output mode connected to it.  The *Pulse* library includes a [`WatchdogSim` sketch](https://github.com/twrackers/Pulse-library/blob/main/examples/WatchdogSim/WatchdogSim.ino) in the `examples` directory.  This sketch shows how the `Pulse` class can be used as a watchdog timer driving the Arduino's built-in LED as its output.  The sketch requires the `OneShot` class and the `StateMachine` class, in addition to the `Pulse` class.

The *Pulse* library also includes a [`Pulse_test` example sketch](https://github.com/twrackers/Pulse-library/blob/main/examples/Pulse_test/Pulse_test.ino), which uses a *Pulse* object to briefly flash the built-in LED, triggered once per second by a *StateMachine* object.  This sketch also requires the `OneShot` and `StateMachine` classes, in addition to the `Pulse` class.

## Dependencies ##

The `Pulse` library requires installation of the `OneShot` and `StateMachine` libraries.

## Installation ##

Instructions for installing the *Pulse* library can be found in file `INSTALL.md` in this repository at [https://github.com/twrackers/Pulse-library/blob/main/INSTALL.md](https://github.com/twrackers/Pulse-library/blob/main/INSTALL.md).

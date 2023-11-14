# GarageSense

An arduino microcontroller program to use a digital input to switch a relay on and off

## Description

This was originally created as a cheap, simple method of identifying if my garage door was open using a limit switch, and arduino, a relay, some wiring, and a old light fixture which in my front door enclosed porch. It takes a digital signal from a limit switch, and uses it to toggle a relay which allows for 120V current to flow into the light fixture, signaling an open garage door.

## Getting Started

### Dependencies

#### Hardware

* Micro Controller (Arduino or otherwise)
* Limit Switch
* Relay

#### Software

* Arduino IDE

OR

* Arduino extention for VS Code

### Installing

* You can simply download `GarageSense.ino` or clone this repository to obtain a copy

### Executing program

* Change/Identify which pins are required for I/O
* Upload the file to the Micro Controller

## Help

I've drawn a very rough circuit diagram called `CircuitDiagram.jpg` in the repo, you can refer to this for wiring assistance.

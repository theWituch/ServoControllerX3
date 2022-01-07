# SCX3
3 Axis **Open-Loop STEP/DIR Position Control** to **Closed-Loop +/-10V Speed Control** Interface

![PCB](Hardware/Layout/SCX3.png)

## About
The system is an interface between two systemically incompatible types of control - open loop STEP/DIR in which there is no feedback, because it is open, and closed loop +/- 10V in which the DIRECT feedback is in the form of the axis position from a linear encoder for a linear axis or rotary for rotary axes (e.g. rotary table).


## How it works

The open-loop CNC controller has no coupling, it only sends STEP/DIR signals and waits for the movement to be performed, e.g. by a stepper motor or servo drive with a STEP / DIR input. This solution is nice and cheap, but it brings with it problems such as the lack of feedback on whether the move was actually made.

Of course, it is possible to detect, for example, in self-drives, the lack of rotation of the motor shaft, but the rotation of the motor does not have to mean the axis shift (failure).

In addition, the entire kinematic chain, which has its efficiency, causes that the positioning from the motor axis is not accurately reflected at the end of the chain (on the machine table).


## Project assumptions

The assumptions for the system were such as to:
* fit on one board for three axes of the machine
* reduce noise on the analog outputs +/- 10V
* ensure internal distribution of the necessary voltages for the system (uC, outputs +/- 10V) and connected encoders from the power supply 12-24VDC
* add a readiness relay (not a safe output, only OK status signaling, as in the servers it was supposed to cooperate with)
* increase the uC computing power
* increase the capacity of the encoder inputs
* integrate the RS232 interface in the system
* and adjust the shape of the board to the format that allows it to be reasonably mounted, e.g. on a DIN rail.


## Progress

The project, due to the fact that while writing the firmware, I encountered a bug with the EEPROM memory built into the uC, it got stuck for a good two years.

Problem: https://www.microchip.com/forums/m1043135.aspx  
Solution: https://www.microchip.com/forums/FindPost/1064146

## Versions

See version description to get more detailed informations.

* [version 1.2.0](V1.2.0.md)
* [version 1.1.0](V1.1.0.md)
* [version 1.0.0](V1.0.0.md)


## License

Whole SCX3 project follow [CC-BY-NC-SA-4.0 license](https://creativecommons.org/licenses/by-nc-sa/4.0/). Thus, project is freely available for academic purpose or individual research, but restricted for commecial use.

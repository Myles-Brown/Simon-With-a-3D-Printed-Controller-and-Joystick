# Simon-With-a-3D-Printed-Controller-and-Joystick

This project offers a twist on the classic memory game Simon. Instead of buttons, the game uses a joystick mounted in a custom 3D-printed controller, along with LEDs, a speaker, an on/off switch, and a battery. These components are connected to a two-layer PCB designed in KiCad, with an Arduino Nano running the game’s code.

# Technologies Used

Fusion

KiCad

Arduino IDE

# Required Tools

1. Soldering iron

2. 22 AWG wire or smaller (the more flexible the wire, the better). The joystick, push button, and four LEDs must all be connected to the PCB with wires, which can make the available space crowded.

3. Heat shrink tubing

4. Super glue (to secure components in place, specifically the push button, LEDs, switch, and joystick).

5. 9V battery connector with wires

# Assembly Instructions

For 3D printing setup information, [click here](https://github.com/ProjectMaker409/Simon-With-a-3D-Printed-Controllor-and-Joystick/blob/main/3D%20Prints/Print%20Information.md).

For information on PCB assembly, [click here](https://github.com/ProjectMaker409/Simon-With-a-3D-Printed-Controllor-and-Joystick/blob/main/Hardware/Manufacturing%20Info.md).

For the list of components, [click here](https://github.com/ProjectMaker409/Simon-With-a-3D-Printed-Controllor-and-Joystick/blob/main/Hardware/SimonSays%20project%20BOM.csv).

To follow along with the component hookup reference, [view this schematic](https://github.com/Myles-Brown/Simon-With-a-3D-Printed-Controllor-and-Joystick/blob/main/Hardware/Schematic%20and%20PCB%20View/Schematic.png).

**Step 1:** Review the 3D printing setup information carefully to ensure the best print quality and proper joystick fit. Then, upload the game code to the Arduino.

**Step 2:** Use super glue to mount the LEDs in the positions shown in the images below: red at the top, blue at the bottom, yellow on the left, and green on the right.

**Step 3:** Use super glue to attach the push button and joystick to the top piece. Attach the buzzer inside the round hole at the front of the bottom piece and the switch inside the small rectangular opening at the back.

**Step 4:** Solder all resistors and the Arduino Nano directly to the PCB, **without installing its pins**. This provides more space for wiring. Then, use glue to secure the PCB in its designated slot.

**Step 5:** Insert the 9V battery into the left side of the controller with its connector attached. Connect the battery’s positive wire to the leftmost terminal of the switch. Then, connect a second wire from the middle terminal of the switch to the PCB’s power through-hole pad. Connect the battery’s ground wire to the PCB’s ground through-hole pad.

**Step 6:** Using flexible 22 AWG wire or smaller, connect all components to the PCB according to the schematic. Use heat shrink tubing to insulate the connections and keep the wiring neat.

**Step 7:** Carefully align the controller’s top plate and use super glue to seal it in place.

# Images and Demo
<img width="428" height="571" alt="IMG_2018" src="https://github.com/user-attachments/assets/4aa9f4c6-bf56-481c-be19-639ac46e0a37" />

<img width="571" height="428" alt="IMG_2020" src="https://github.com/user-attachments/assets/b1ff723a-055b-438f-87a6-43500bdff5e7" />

https://github.com/user-attachments/assets/5cbe7676-d3d7-4ec1-9f7e-f7e391b760e8




# Z80 Arduino System

Emulated System implementing [ArduZ80 Library](https://github.com/MohammedRashad/ArduZ80)

# Introduction
Project that makes use of the ArduZ80 Library, and using some hardware blocks to emulate hardware of a generic computer
system consisting of input device, output device and memory module and making a front end for the user to interact with the system.

# Structure

__The Project Consists of 4 Modules :__<br/>

- Emulation Library Handler<br/>
- Memory Module<br/>
- keypad Module<br/>
- LCD Module<br/>

__Hardware :__<br/>

- SD Card<br/>
- 4x4 Keypad<br/>
- 16x2 LCD<br/>
- Arduino Mega<br/>

# Description

**1. Emulation handler :**<br/>
- Implements the I/O Functions from the library and use them to connect with a keypad and an LCD module.<br/>
- Frontend for users to interact with the emulator.<br/>

**2. Keypad :**<br/>
- Contains Definitions and data for activating and using the Keypad.<br/>

**3. LCD Module :**<br/>
- Contains the interface to the Emulation handler (Frontend) and acts as the output in I/O.<br/>

**4. Memory :**<br/>
- Simulates the ROM to the microprocessor, also serves as a data logger module for the debug mode.<br/>

# License 

This library is signed under MIT License, Reproduce under it's terms.

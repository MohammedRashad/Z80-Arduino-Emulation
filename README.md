# Z80-Arduino-System

Emulated System implementing ArduZ80 Library

# Structure

__The Project Consists of 4 Modules :__<br/>

- Emulation Library Handler<br/>
- Memory Module<br/>
- keypad Module<br/>
- LCD Module<br/>

**1. Emulation handler :**<br/>
- Implements the I/O Functions from the library and use them to connect with a keypad and an LCD module.<br/>
- Frontend for users to interact with the emulator.<br/>

**2. Keypad :**<br/>
- Contains Definitions and data for activating and using the Keypad.<br/>

**3. LCD Module :**<br/>
- Contains the interface to the Emulation handler (Frontend) and acts as the output in I/O.<br/>

**2. Memory :**<br/>
- Simulates the ROM to the microprocessor, also serves as a data logger module for the debug mode.<br/>

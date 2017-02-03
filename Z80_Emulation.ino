/*
 *   Z80 Emulator on Arduino
 *   This project is signed under MIT License, use it with respect to the terms of the license.
 *
 *   Features:
 *   -----------
 *
 *   - Interpretation-Based.
 *   - Two modes, Debug and Run.
 *   - Runs 100% on arduino, using a PC is optional.
 *   - Modular Design, allowing freedom in emulation.
 *   - Supports all Arduino (Tested on Uno, Mega, Nano).
 *   - Built over ArduZ80 , the first Z80 emulation library for Arduino.
 *   
 *   
 *   Modules :
 *   -----------
 *
 *   - Keypad  (as Input Device)
 *   - SD card (as RAM)
 *   - LCD Screen  (as output device)
 *   - Emulator Handling layer
 *
 *
 */

#include <LiquidCrystal.h>
#include <MenuBackend.h>
#include <Keypad.h>
#include <SPI.h>
#include <SD.h>

#include <ArduZ80.h>

ArduZ80 cpu;

void setup() {
 
  Serial.begin(9600);

  initRAM();
  
  initLCD();

}

void loop() {
  
  Emulator();
  
}


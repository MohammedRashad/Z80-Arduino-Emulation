/*
 * Memory Module
 *
 * This module works as a data logger for debugging mode
 * Also works as a ROM for the emulation system
 *
 * Functions : initRAM , readRAM , write RAM
 *
 */

File myFile;

uint8_t memory[4096];


/*
 *  Function : initRAM
 *  Parameters : NULL
 *
 *  Works to initalize the SD card Module and Activates SPI
 *
 */
void initRAM() {


  Serial.print("Initializing RAM...");

  if (!SD.begin(53)) {

    Serial.println("initialization failed!");
    return;

  }


  Serial.println("initialization done.");

}

/*
 *  Function : writeRAM
 *  Parameters : data
 *  works to write any logging data to SD card
 *
 */
void writeRAM(String data) {

  myFile = SD.open("log.txt", FILE_WRITE);

  if (myFile) {

    Serial.print("file opened.");
    myFile.println(data + "\n\n");
    myFile.close();
    Serial.println("done.");

  } else {

    Serial.println("error opening log.txt");

  }

}

/*
 *  Function : ReadRAM
 *  Parameters : NULL
 *
 *  works to read the program wether from an array or SD card module
 *
 */
void readRAM() {


  myFile = SD.open("code.txt");

  if (myFile) {

    Serial.println("Reading to Z80...\n");
    delay(1000);

    //This is the Assembly program, Multiply 3 * 5, xor the result with 0x53

    uint8_t t[30] = {

      EXT_FD, FD_LD_A_imm, 0x00,
      EXT_DD, DD_LD_B_imm, 0x05,
      EXT_DD, DD_LD_C_imm, 0x03,
      ADD_A_C,
      DJNZ, 0x09,

      XOR_A_imm, 0xFF,
      OUT_nn_A , 0x53,

      NOP
    };

    ////////////////Copy to RAM///////////////////////

    for (int i = 0; i < 30; i++) {

      cpu.ram_[i] = t[i];

      writeRAM((string cpu.ram_[i]);

    }

    /////////////////Other Method, copy from SD/////////////////////

    //    while(myFile.available()){
    //
    //      cpu.ram_[i] = myFile.read();
    //
    //    }

    
    myFile.close();

  } else {

    Serial.println("error opening code.txt");
  }

}




/*
 * Keypad Module
 * 
 * This Module Works as a controller for the front end
 * Also as an Input Device for the Z80 Emulation
 * 
 * Functions : get
 * 
 */

const byte Rows= 4;  
const byte Cols= 4;  
 
char keymap[Rows][Cols]= {
  
    {'1', '2', '3','A'},
    {'4', '5', '6','B'},
    {'7', '8', '9','C'},
    {'*', '0', '#','D'}

};

byte rPins[Rows]= {A8,A9,A10,A11}; 
byte cPins[Cols]= {A12,A13,A14,A15};

Keypad kpd = Keypad(makeKeymap(keymap), rPins, cPins, Rows, Cols);


/*
 * Function : get
 * Parameters : NULL
 * Works to get a character from Keypad and send it to the emulation front end
 * 
 */
char get(){

  return kpd.getKey();
  
}


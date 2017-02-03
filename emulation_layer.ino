/*
 *  Emulation Layer
 *  
 *  This module implements the I/O functions from ArduZ80 and handles IO operations
 *  Works as a bridge between emulator core and emulated hardware.
 *  
 *  Functions : write_io , read_io
 *  
 */


/* 
 *  Function : write_io 
 *  Parameters : address, value
 *  
 *  Works when "IN (nn),A" instruction executes
 *  user can change implmentation to serial monitor, graphical lcd, tv, vga
 * 
 */
void ArduZ80::write_io(uint16_t addr, uint8_t val) {

  print(val);

}


/* 
 *  Function : read_io 
 *  Parameters : address, value
 *  
 *  Works when "OUT  A,(nn)" instruction executes
 *  user can change implmentation to serial monitor, graphical lcd, tv, vga
 * 
 */
uint8_t ArduZ80::read_io(uint16_t addr) {

  char keypressed = get();

  return (uint8_t) keypressed;
}


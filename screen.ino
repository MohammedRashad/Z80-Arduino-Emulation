/*
 * 
 *   LCD Module
 *   Works as Output Device to the Emulator
 *   Also works as an interface for the emulator system front end
 *   
 *   Functions : initLCD , Emulator , menuChanged , print , menuUsed
 *   
 */

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*
 * Menu organization : 
 * 
 * 1. Emulator
 *      a.run
 *      b. debug
 *      
 * 2. Credits
 * 
 */
MenuBackend menu = MenuBackend(menuUsed, menuChanged);

MenuItem menu1Item1 = MenuItem("Item1");
MenuItem menuItem1SubItem1 = MenuItem("Item1SubItem1");
MenuItem menuItem1SubItem2 = MenuItem("Item1SubItem2");
MenuItem menu1Item2 = MenuItem("Item2");

/* 
 * Function : initLCD 
 * Parameters : NULL
 *
 * Works to initalize the LCD itself and make it work
 * 
 */
void initLCD() {

  menu.getRoot().add(menu1Item1);
  menu1Item1.addRight(menu1Item2);
  menu1Item1.add(menuItem1SubItem1).addRight(menuItem1SubItem2);

  menu.toRoot();

  lcd.begin(16, 2);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Z80 Emulator  ");
  lcd.setCursor(0, 1);
  lcd.print("Press A to Start");

}

/*
 * Function : Emulator 
 * Parameters : NULL
 * Works to start the frontend of emulation and allow user to begin exploring the emulation
 */
void Emulator() {

  MenuItem currentMenu = menu.getCurrent();
  
  char keypressed = kpd.getKey();

  if (keypressed) Serial.println(keypressed);
  
  switch (keypressed) {

    case 'A':

      if (!(currentMenu.moveDown())) {

        menu.use();

      } else {

        menu.moveDown();
      }

      break;

    case 'B':
      menu.toRoot();
      break;

    case 'C':
      menu.moveRight();
      break;

    case 'D':
      menu.moveLeft();
      break;
  }

}

/*
 * Function : MenuChanged (Impleneted From Library)
 * Parameter : changed
 * 
 * Works when a button is pressed and action item is changed
 * 
 */

void menuChanged(MenuChangeEvent changed) {

  MenuItem newMenuItem = changed.to;

  if (newMenuItem.getName() == menu.getRoot()) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Z80 Emulator  ");
    lcd.setCursor(0, 1);
    lcd.print("Press A to Start");


  } else if (newMenuItem.getName() == "Item1") {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("1. Emulator   ");

  } else if (newMenuItem.getName() == "Item1SubItem1") {

    lcd.setCursor(0, 1);
    lcd.print("a. Run   ");

    //Start Emulation

  } else if (newMenuItem.getName() == "Item1SubItem2") {

    lcd.setCursor(0, 1);
    lcd.print("b. Debug   ");

    //Start Emulation with log printing

  } else if (newMenuItem.getName() == "Item2") {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("2. Credits   ");

  }

}


/*
 * Function : MenuUsed (Impleneted From Library)
 * Parameter : used
 * 
 * Works when an element is choosen in the menu to make the action assigned to it
 * 
 */
void menuUsed(MenuUseEvent used) {


  if (used.item.getName() == "Item1SubItem1") {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Running..             ");
    readRAM();
    cpu.run_to_nop(true);

  } else if (used.item.getName() == "Item1SubItem2") {
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Debugging..           ");
    readRAM();
    cpu.run_to_nop(true);

  } else if (used.item.getName() == "Item2") {

    lcd.clear();
    lcd.setCursor(0, 0);

    lcd.print("Built by : ");


    lcd.setCursor(0, 1);
    lcd.print("Mohamed Rashad        ");
    delay(1500);

    lcd.setCursor(0, 2);
    lcd.print("Bavly Abd ElMasih     ");
    delay(1500);

    lcd.setCursor(0, 3);
    lcd.print("Moatasm Shehta        ");
    delay(1500);

    lcd.setCursor(0, 4);
    lcd.print("Mohamed AbdElNaby    ");
    delay(1500);

    lcd.setCursor(0, 5);
    lcd.print("Mohanad Mohsen       ");
    delay(1500);

    menu.toRoot();

  }

}

/* 
 * Function : print
 * Parameters : val
 * Takes data from write_io and print it to lcd
 * 
 */
void print(uint8_t val) {

  lcd.setCursor(0, 1);
  lcd.print("OUT : ");
  lcd.print(val);

}



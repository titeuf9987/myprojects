
/***************************
 * Key pad variables
 *************************/
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6, 5}; //connect to the column pinouts of the keypad



Keypad keypad= Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );




void initKeyboard(void){
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
}


// Taking care of some special events.
void keypadEvent(KeypadEvent key) {
//  char key = keypad.getKey();

  switch (keypad.getState()) {
    case PRESSED:
      //Serial.println(key);
      if (key == '1'||key == '2'||key == '3'||key == '4') {
        mode = key;
      }
      if (mode == '1') processKeyMode1(key);
      if (mode == '2') processKeyMode2(key);
      if (mode == '3') processKeyMode3(key);
      if (mode == '4') processKeyMode4(key);
      break;
    /*
    case RELEASED:
      break;

    case HOLD:
      break;
      */
  }
}


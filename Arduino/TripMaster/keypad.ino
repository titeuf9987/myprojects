void initKeyboard(void){
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad

}


// Taking care of some special events.
void keypadEvent(KeypadEvent key) {
//  char key = keypad.getKey();

  switch (keypad.getState()) {
    case PRESSED:
      Serial.println(key);
      if (key == '1') {
        mode = '1';
      }
      if (key == '2') {
        mode = '2';
      }
      if (key == '3') {
        mode = '3';
      }
      if (key == '4') {
        mode = '4';
      }
      if (mode == '1') processKeyMode1(key);
      if (mode == '2') processKeyMode2(key);
      if (mode == '3') processKeyMode3(key);
      if (mode == '4') processKeyMode4(key);
      break;

    case RELEASED:
      break;

    case HOLD:
      break;
  }
}


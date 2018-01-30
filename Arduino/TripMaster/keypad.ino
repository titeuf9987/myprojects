
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
      if (mode == '1') processMode1(key);
      if (mode == '2') processMode2(key);
      if (mode == '3') processMode3(key);
      if (mode == '4') processMode4(key);
      break;

    case RELEASED:
      break;

    case HOLD:
      break;
  }
}


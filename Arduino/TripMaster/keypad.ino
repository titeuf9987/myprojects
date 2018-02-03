



void initKeypad(void){
    Serial.println("Init KP");
    keypad.addEventListener(keypadEvent); // Add an event listener for this keypad
}


// Taking care of some special events.
void keypadEvent(KeypadEvent key) {
  Serial.println("Event");
  //char key = keypad.getKey();

  switch (keypad.getState()) {
    case PRESSED:
      Serial.println(key);
      if (key == '1'||key == '2'||key == '3'||key == '4') {
        mode = key;
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


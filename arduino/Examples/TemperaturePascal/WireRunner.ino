
#define wire_extension1 B00100001
#define wire_extension2 B00100111

#define wire_lcd B00100000
LiquidCrystal lcd(wire_lcd);
boolean lcdInitialized=false;

unsigned int wireEventStatus=0;

 

void setupWireRunner() {
}

void runWire() {
  wireEventStatus++;

  if (wireDeviceExists(wire_extension1)) {
    // Serial.println("Device exists");
    if (wireEventStatus%2==1) {
      wireWrite(wire_extension1,B01010101);
    }
    if (wireEventStatus%2==0) {
      wireWrite(wire_extension1,B10101010);
    }
  } 
  if (wireDeviceExists(wire_extension2)) {
    // Serial.println("Device exists");
    if (wireEventStatus%2==1) {
      wireWrite(wire_extension2,B11110000);
    }
    if (wireEventStatus%2==0) {
      wireWrite(wire_extension2,B00001111);
    }
  }

  if (wireDeviceExists(wire_lcd)) {
    if (! lcdInitialized) {
      lcdInitialized=true;
      lcd.begin(16, 2);
      // Print a message to the LCD.
      lcd.setCursor(0,0);
      lcd.print("Current:");
      lcd.setCursor(0,1);
      lcd.print("<:");
      lcd.setCursor(7,1);
      lcd.print(">:");
    }

    lcd.setCursor(10,0);
    lcd.print(getParameter(20));
   lcd.setCursor(2,1);
    lcd.print(getParameter(21));
    lcd.setCursor(10,1);
    lcd.print(getParameter(22));
  } 
  else {
    lcdInitialized=false; 
  }


}






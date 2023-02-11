 

#include <IRremote.h>
#include <LiquidCrystal.h>

#define PIN_RECV 2 // Signal Pin of IR receiver

IRrecv receiver(PIN_RECV);

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup()
{
  lcd.begin(16, 2);
  lcd.print("<press a button>");
  receiver.enableIRIn(); // Start the receiver
}

void loop()
{
  // Checks received an IR signal
  if (receiver.decode()) {
    translateIR();
    receiver.resume();  // Receive the next value
  }
}

void lcdPrint(char* text)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("button pressed:");
  lcd.setCursor(0, 1);
  lcd.print(text);
  lcd.print(" code: ");
  lcd.print(receiver.decodedIRData.command);
}

void translateIR()
{
  // Takes command based on IR code received
  switch (receiver.decodedIRData.command) {
    case 162:
      lcdPrint("POWER");
      break;
    case 226:
      lcdPrint("MENU");
      break;
    case 34:
      lcdPrint("TEST");
      break;
    case 2:
      lcdPrint("PLUS");
      break;
    case 194:
      lcdPrint("BACK");
      break;
    case 224:
      lcdPrint("PREV.");
      break;
    case 168:
      lcdPrint("PLAY");
      break;
    case 144:
      lcdPrint("NEXT");
      break;
    case 104:
      lcdPrint("NUM: 0");
      break;
    case 152:
      lcdPrint("MINUS");
      break;
    case 176:
      lcdPrint("KEY: C");
      break;
    case 48:
      lcdPrint("NUM: 1");
      break;
    case 24:
      lcdPrint("NUM: 2");
      break;
    case 122:
      lcdPrint("NUM: 3");
      break;
    case 16:
      lcdPrint("NUM: 4");
      break;
    case 56:
      lcdPrint("NUM: 5");
      break;
    case 90:
      lcdPrint("NUM: 6");
      break;
    case 66:
      lcdPrint("NUM: 7");
      break;
    case 74:
      lcdPrint("NUM: 8");
      break;
    case 82:
      lcdPrint("NUM: 9");
      break;
    default:
      lcd.clear();
      lcd.print(receiver.decodedIRData.command);
      lcd.print(" other button");
  }
}

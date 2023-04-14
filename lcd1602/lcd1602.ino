/********************************
   name:I2C LCD1602
   function:You should now see your I2C LCD1602 display the flowing characters: "SunFounder" and "hello, world".
 ********************************/
// WIRING: http://wiki.sunfounder.cc/index.php?title=I%C2%B2C_LCD1602
// Email:support@sunfounder.com
// Website:www.sunfounder.com

/********************************/
// include the library code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
/**********************************************************/
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display
/*********************************************************/
void setup()
{
  Serial.begin(115200);
  lcd.init();      // initialize the lcd
  lcd.backlight(); // open the backlight
  pinMode(2, OUTPUT);
}
/*********************************************************/
void loop()
{
  lcd.setCursor(2, 0);       // set the cursor to column 3, line 0
  lcd.print("Kissing your"); // Print a message to the LCD

  lcd.setCursor(0, 1);           // set the cursor to column 2, line 1
  lcd.print("homies isn't gay"); // Print a message to the LCD.

  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);
}
/************************************************************/

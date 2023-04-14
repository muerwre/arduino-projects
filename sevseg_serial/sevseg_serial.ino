#include "SevSeg.h"

// WIRING: https://www.circuitbasics.com/arduino-7-segment-display-tutorial/

int analogPin = 0; // номер порта к которому подключен потенциометр
float val = 0;     // переменная для хранения считываемого значения
int last_rounded = 0;

SevSeg sevseg;

void setup()
{
  Serial.begin(115200); //  установка связи по serial
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  bool resistorsOnSegments = false;     // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = true;         // Default 'false' is Recommended
  bool leadingZeros = false;            // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true;          // Use 'true' if your decimal point doesn't exist or isn't connected

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(10);
  Serial.setTimeout(10);
}

void loop()
{
  if (Serial.available() > 0)
  {
    Serial.print("received: ");
    val = Serial.parseInt();
    Serial.println(val);
  }

  sevseg.setNumber(val);
  sevseg.refreshDisplay();

  delay(5);
}

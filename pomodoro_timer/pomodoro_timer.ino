// Example: https://wokwi.com/projects/289186888566178317
// FontGen: https://pjrp.github.io/MDParolaFontEditor
// Examples: https://github.com/MajicDesigns/MD_Parola/tree/main/examples

// Header file includes
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include "Format.h"
#include "Fonts7seg.h"

// Buttons
int PAUSE_PIN = 2;
int lastPausePinStatus = LOW;
int NEXT_PIN = 3;
int lastNextPinStatus = LOW;

// Beepers
int BEEPER_PIN = 5;
int beeperFreq = 1000;
int beeperDuration = 150;

// LEDs
#define USE_GENERIC_HW 1
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 3 // Define the number of displays connected
#define CLK_PIN 13    // CLK or SCK
#define DATA_PIN 11   // DATA or MOSI
#define CS_PIN 10     // CS or SS

MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Durations
const int WORK_DURATION = 24 * 60;      // 25 * 60
const int REST_DURATION = 6 * 60;       // 5 * 60
const int LONG_REST_DURATION = 16 * 60; // 15 * 60
const int TOTAL_CYCLES = 4;

// Timer values
int timer = 0;
char timerString[32] = "";

// Pause
bool paused = false;
int cycleNumber = 0;
unsigned long timing;
int second = 1000;
int blinkDuration = 250;
int blinkTimer = 0;

enum Mode
{
  Clock,
  Work,
  Rest,
};

Mode mode = Work;

void setup()
{
  pinMode(PAUSE_PIN, INPUT);
  pinMode(NEXT_PIN, INPUT);

  Serial.begin(115200);

  P.begin();
  P.setFont(compact);
  P.setSpeed(10);

  setTimer(WORK_DURATION);
  beepBeep();
  pause();
  setMode(Work);
}

void loop()
{
  display();

  checkPauseButton();
  checkNextButton();

  if (paused || millis() - timing < second)
  {
    return;
  }

  timing = millis();

  switch (mode)
  {
  case Clock:
    return;
  default:
    tick();
    return;
  }
}

void setTimer(int val)
{
  timer = val;
}

void setMode(Mode m)
{
  mode = m;
}

void pause()
{
  blinkTimer = millis();
  paused = true;
}

void resume()
{
  timing = millis();
  paused = false;
}

void tick()
{
  timer--;

  if (timer < 0)
  {
    beepBeep();
    next();
    return;
  }
}

void setCycle(int cycle)
{
  cycleNumber = cycle;
}

void next()
{
  timing = millis();

  if (cycleNumber == TOTAL_CYCLES - 1)
  {
    if (mode == Work)
    {
      setTimer(LONG_REST_DURATION);
      setMode(Rest);
      return;
    }

    pause();
    setCycle(0);
    setMode(Work);
    setTimer(WORK_DURATION);

    return;
  }

  if (mode == Work)
  {
    setTimer(REST_DURATION);
    setMode(Rest);
    return;
  }

  pause();
  setCycle(cycleNumber + 1);
  setTimer(WORK_DURATION);
  setMode(Work);
}

void display()
{
  P.displayAnimate();

  if (paused)
  {
    int now = millis();
    int diff = now - blinkTimer;

    if (blinkTimer == 0 || diff > blinkDuration)
    {
      blinkTimer = now;
    }

    if (float(diff) < floor((float)blinkDuration / 2))
    {
      P.displayText("", PA_CENTER, P.getSpeed(), P.getPause(), PA_NO_EFFECT, PA_NO_EFFECT);
      return;
    }
  }

  formatTime(timerString, timer);
  P.displayText(timerString, PA_CENTER, P.getSpeed(), P.getPause(), PA_NO_EFFECT, PA_NO_EFFECT);
}

void beep()
{
  tone(BEEPER_PIN, beeperFreq, beeperDuration);
}

void beepBeep()
{
  tone(BEEPER_PIN, beeperFreq, beeperDuration);
  delay(beeperDuration * 1.5);
  tone(BEEPER_PIN, beeperFreq, beeperDuration);
}

void checkPauseButton()
{
  if (digitalRead(PAUSE_PIN) == HIGH && lastPausePinStatus != HIGH)
  {
    beep();

    lastPausePinStatus = HIGH;
    if (paused)
    {
      resume();
    }
    else
    {
      pause();
    }
  }
  else if (lastPausePinStatus != digitalRead(PAUSE_PIN))
  {
    lastPausePinStatus = LOW;
  }
}

void checkNextButton()
{
  if (digitalRead(NEXT_PIN) == HIGH && lastNextPinStatus != HIGH)
  {

    lastNextPinStatus = HIGH;
    beep();
    next();
    resume();
  }
  else if (lastNextPinStatus != digitalRead(NEXT_PIN))
  {
    lastNextPinStatus = LOW;
  }
}
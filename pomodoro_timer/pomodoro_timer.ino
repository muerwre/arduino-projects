// Example: https://wokwi.com/projects/289186888566178317
// FontGen: https://pjrp.github.io/MDParolaFontEditor
// Examples: https://github.com/MajicDesigns/MD_Parola/tree/main/examples

#include <MD_MAXPanel.h>

#include "Format.h"
#include "Fonts7seg.h"
#include "Beep.h"
#include "Button.h"

// Buttons
int PAUSE_PIN = 2;
int lastPausePinStatus = LOW;
int NEXT_PIN = 3;
int lastNextPinStatus = LOW;

// LEDs
#define USE_GENERIC_HW 1
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 3 // Define the number of displays connected
#define CLK_PIN 13    // CLK or SCK
#define DATA_PIN 11   // DATA or MOSI
#define CS_PIN 10     // CS or SS

MD_MAXPanel mp = MD_MAXPanel(HARDWARE_TYPE, CS_PIN, 3, 1);

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

void onPausePress()
{
  beep();

  if (paused)
  {
    resume();
  }
  else
  {
    pause();
  }
}

void onNextPress()
{
  beep();
  next();
  resume();
}

Button pauseButton = Button(PAUSE_PIN, onPausePress);
Button nextButton = Button(NEXT_PIN, onNextPress);

void setup()
{
  Serial.begin(115200);

  pauseButton.begin();
  nextButton.begin();

  mp.begin();
  mp.setFont(compact);

  setTimer(WORK_DURATION);
  beepBeep();
  pause();
}

void loop()
{
  drawTime();
  drawMode();

  pauseButton.check();
  nextButton.check();

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
  mp.clear();
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

void drawTime()
{
  formatTime(timerString, timer);
  mp.drawText(5, 7, timerString, MD_MAXPanel::ROT_0);
}

void drawMode()
{
  if (mode == Clock)
  {
    mp.drawText(1, 6, "c", MD_MAXPanel::ROT_0);
    return;
  }

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
      mp.drawText(1, 6, " ", MD_MAXPanel::ROT_0);
      return;
    }
  }

  switch (mode)
  {
  case Work:
    mp.drawText(1, 6, "w", MD_MAXPanel::ROT_0);
    return;
  case Rest:
    mp.drawText(1, 6, "r", MD_MAXPanel::ROT_0);
    return;
  }
}

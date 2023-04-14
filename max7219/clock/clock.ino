// Example: https://wokwi.com/projects/289186888566178317
// FontGen: https://pjrp.github.io/MDParolaFontEditor
// Examples: https://github.com/MajicDesigns/MD_Parola/tree/main/examples

// Header file includes
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include "Format.h"
// #include "Fonts7seg.h"

// Buttons
int PAUSE_PIN = 2;
int NEXT_PIN = 3;

// LEDs
#define USE_GENERIC_HW 1
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 3 // Define the number of displays connected
#define CLK_PIN 13    // CLK or SCK
#define DATA_PIN 11   // DATA or MOSI
#define CS_PIN 10     // CS or SS

MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

// Durations
const int WORK_DURATION = 25;      // 25 * 60
const int REST_DURATION = 5;       // 5 * 60
const int LONG_REST_DURATION = 15; // 15 * 60
const int TOTAL_CYCLES = 4;

// Timer values
int timer = 0;
char timerString[32] = "";

// Pause
bool paused = false; // TODO: true
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
  // P.setFont(compact);
  P.setSpeed(10);

  setTimer(WORK_DURATION);
  pause(); // TODO: uncomment
  setMode(Work);
}

void loop()
{
  display();

  if (digitalRead(PAUSE_PIN) == HIGH)
  {
    if (paused)
    {
      resume();
      delay(1000);
    }
    else
    {
      pause();
      delay(1000);
    }
  }

  if (digitalRead(NEXT_PIN) == HIGH)
  {
    next();
    resume();
    delay(1000);
  }

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
  paused = true;
}

void resume()
{
  paused = false;
}

void tick()
{
  timer--;

  if (timer < 0)
  {
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

  itoa(timer, timerString, 10);
  // P.displayText(timerString, PA_CENTER, P.getSpeed(), P.getPause(), PA_NO_EFFECT, PA_NO_EFFECT);
  P.displayText(timerString, PA_CENTER, P.getSpeed(), P.getPause(), PA_NO_EFFECT, PA_NO_EFFECT);
}
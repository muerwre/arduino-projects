// Example: https://wokwi.com/projects/289186888566178317
// FontGen: https://pjrp.github.io/MDParolaFontEditor
// Examples: https://github.com/MajicDesigns/MD_Parola/tree/main/examples

#include <MD_MAXPanel.h>

#include "Fonts7seg.h"
#include "Pomodoro.h"
#include "Button.h"

// LEDs
#define USE_GENERIC_HW 1
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 3 // Define the number of displays connected
#define CLK_PIN 13    // CLK or SCK
#define DATA_PIN 11   // DATA or MOSI
#define CS_PIN 10     // CS or SS
MD_MAXPanel mp = MD_MAXPanel(HARDWARE_TYPE, CS_PIN, 3, 1);

// Screens
enum Screens
{
  Clock,
  Pomodoro,
};

Screens screen = Pomodoro;
PomodoroScreen pomodoro = PomodoroScreen();
Screen &currentScreen = pomodoro;

// Buttons
int PAUSE_PIN = 2;
int NEXT_PIN = 3;

void pause()
{
  currentScreen.onPause();
}

void next()
{
  currentScreen.onNext();
}

Button pauseButton = Button(PAUSE_PIN, pause);
Button nextButton = Button(NEXT_PIN, next);

void setup()
{
  Serial.begin(115200);

  pauseButton.begin();
  nextButton.begin();

  mp.begin();
  mp.setFont(compact);

  currentScreen.begin();
}

void loop()
{
  pauseButton.check();
  nextButton.check();

  drawTime();
  drawMode();

  currentScreen.tick();
}

void drawTime()
{
  mp.drawText(5, 7, currentScreen.getValue(), MD_MAXPanel::ROT_0);
}

void drawMode()
{
  mp.drawText(1, 6, currentScreen.getMode(), MD_MAXPanel::ROT_0);
}

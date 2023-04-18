#pragma once

#include "Screen.h";
#include "Format.h";

class TimerScreen : public Screen
{
public:
  char *getValue() override
  {
    formatTime(timerString, timer);
    return timerString;
  }

  char *getMode() override
  {
    return "t";
  }

  void tick() override
  {
    if (millis() - timing < second)
    {
      return;
    }

    timing = millis();
    updateTimer();
  }

  void begin() override
  {
    timer = 0;
  }

private:
  int timer = 0;
  int second = 1000;
  unsigned long timing;
  char timerString[8] = "";

  void updateTimer()
  {
    if (timer > 59 * 60)
    {
      timer = 0;
      return;
    }

    timer++;
  }
};

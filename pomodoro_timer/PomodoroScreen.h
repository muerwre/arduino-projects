#pragma once

#include "Screen.h"
#include "Beep.h"
#include "Format.h"

enum Mode
{
  Work,
  Rest,
};

class PomodoroScreen : public Screen
{
public:
  char *getMode() override
  {

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
        return " ";
      }
    }

    switch (mode)
    {
    case Work:
      return "w";
    case Rest:
      return "r";
    };
  }

  char *getValue() override
  {
    formatTime(timerString, timer);
    return timerString;
  }

  void begin() override
  {
    setTimer(WORK_DURATION);
    setMode(Work);
    setCycle(0);
    beepBeep();
    pause();
  }

  void tick() override
  {
    if (paused || millis() - timing < second)
    {
      return;
    }

    timing = millis();
    updateTimer();
  }

  void onPause() override
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

  void onNext() override
  {
    beep();
    next();
    resume();
  }

private:
  // Durations
  const int WORK_DURATION = 24 * 60;      // 25 * 60
  const int REST_DURATION = 6 * 60;       // 5 * 60
  const int LONG_REST_DURATION = 16 * 60; // 15 * 60
  const int TOTAL_CYCLES = 4;

  // Timer values
  int timer = 0;
  char timerString[8] = "";

  // Pause
  bool paused = false;
  int cycleNumber = 0;
  unsigned long timing;
  int second = 1000;
  int blinkDuration = 250;
  int blinkTimer = 0;

  // Mode
  Mode mode = Work;

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

  void updateTimer()
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
};


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
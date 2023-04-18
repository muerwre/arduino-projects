
// Beepers
int BEEPER_PIN = 5;
int beeperFreq = 1000;
int beeperDuration = 150;

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

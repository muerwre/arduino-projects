
void formatTime(char *to, int value)
{
  int mins = (float(value) / 60);
  int secs = value - (mins * 60);

  char secsStr[8] = "";
  char minsStr[8] = "";

  if (secs < 10)
  {
    sprintf(secsStr, "0%d", secs);
  }
  else
  {
    sprintf(secsStr, "%d", secs);
  }

  if (mins < 10)
  {
    sprintf(minsStr, " %d", mins);
  }
  else
  {
    sprintf(minsStr, "%d", mins);
  }

  sprintf(to, "%s:%s", minsStr, secsStr);
}
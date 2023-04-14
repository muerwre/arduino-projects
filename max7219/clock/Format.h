
void formatTime(char *to, int value)
{
  int mins = (float(value) / 60);
  int secs = value - (mins * 60);

  if (secs < 10)
  {
    sprintf(to, "%d:0%d", mins, secs);
    return;
  }

  sprintf(to, "%d:%d", mins, secs);
}
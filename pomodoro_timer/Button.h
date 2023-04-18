int LONG_PRESS_DURATION = 500;

class Button
{
public:
  void (*onPress)();
  void (*onLongPress)();

  Button(int PIN, void (*onPressCallback)(), void (*onLongPressCallback)())
  {
    pin = PIN;
    onPress = onPressCallback;
    onLongPress = onLongPressCallback;
  };

  Button(int PIN, void (*onPressCallback)())
  {
    pin = PIN;
    onPress = onPressCallback;
  };

  Button(int PIN)
  {
    pin = PIN;
  };

  void begin()
  {
    pinMode(pin, INPUT);
  }

  void check()
  {
    // no handlers specified
    if (onPress == NULL && onLongPress == NULL)
    {
      return;
    }

    if (digitalRead(pin) == LOW)
    {
      // nothing happened
      if (pressedSince == 0)
      {
        return;
      }

      if (millis() - pressedSince > LONG_PRESS_DURATION && onLongPress != NULL)
      {
        onLongPress();
        pressedSince = 0;
        return;
      }

      onPress();
      pressedSince = 0;
    }

    if (digitalRead(pin) == HIGH)
    {
      // press started
      if (pressedSince != 0)
      {
        return;
      }

      pressedSince = millis();
      return;
    }
  }

  void setOnPress(void (*onPressCallback)())
  {
    onPress = onPressCallback;
  }

  void setOnLongPress(void (*onLongPressCallback)())
  {
    onPress = onLongPressCallback;
  }

private:
  int lastPausePinStatus = HIGH;
  int pressedSince = 0;
  int pin = 0;
};

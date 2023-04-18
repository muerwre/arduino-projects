#pragma once

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

    int const isLongPress = millis() - pressedSince > LONG_PRESS_DURATION;

    if (digitalRead(pin) == LOW)
    {
      // nothing happened OR already fired
      if (pressedSince == 0)
      {
        return;
      }

      // debounce keypresses
      delay(100);

      // trigger was fired on HIGH state
      if (triggerFired)
      {
        pressedSince = 0;
        triggerFired = false;
        delay(100);
        return;
      }

      // the press was long
      if (isLongPress && onLongPress != NULL)
      {
        onLongPress();
        pressedSince = 0;
        return;
      }

      onPress();
      pressedSince = 0;
      return;
    }

    if (digitalRead(pin) == HIGH)
    {
      // press started
      if (pressedSince != 0)
      {
        // already fired, but user keeps pressing button
        if (triggerFired)
        {
          return;
        }

        // if no long press, fire short one immediately
        if (onLongPress == NULL)
        {
          triggerFired = true;
          onPress();
          return;
        }

        // handle long press if user still holds the button
        if (isLongPress)
        {
          triggerFired = true;
          onLongPress();
          return;
        }

        return;
      }

      // first press event

      triggerFired = false;
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
  bool triggerFired = false;
};

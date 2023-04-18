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
    pressedSince = 0;
    triggerFired = false;
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
      // nothing happened
      if (pressedSince == 0)
      {
        return;
      }

      pressedSince = 0;

      // trigger was fired on HIGH state
      if (triggerFired)
      {
        pressedSince = 0;
        triggerFired = false;
        return;
      }

      // the press was long
      if (isLongPress && onLongPress != NULL)
      {
        onLongPress();
        return;
      }

      onPress();
      return;
    }

    if (digitalRead(pin) == HIGH)
    {
      // press started
      if (pressedSince == 0)
      {
        // first press event
        triggerFired = false;
        pressedSince = millis();
        return;
      }

      // already fired, but user keeps pressing button
      if (triggerFired)
      {
        pressedSince = millis();
        return;
      }

      // handle long press if user still holds the button
      if (onLongPress != NULL && millis() - pressedSince > LONG_PRESS_DURATION)
      {
        triggerFired = true;
        pressedSince = 0;
        onLongPress();
        return;
      }

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

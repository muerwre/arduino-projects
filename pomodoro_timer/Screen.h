#pragma once
class Screen
{
public:
  virtual void begin() {}
  virtual void stop() {}
  virtual void tick() {}
  virtual void onPause() {}
  virtual void onNext() {}

  virtual char *getMode() {}
  virtual char *getValue()
  {
    return "1111";
  };
};

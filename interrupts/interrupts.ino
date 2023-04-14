volatile byte count;
byte prevCount = 0;

void setup()
{
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(1, myInterrupt, FALLING);
  Serial.begin(115200);
  Serial.println("Let's go!");
}

void loop()
{

  // if (prevCount != count)
  // {
  // prevCount = count;
  Serial.println(count);
  // }

  delay(500);
}

void myInterrupt()
{
  count++;
}
#include <Stepper.h>
#include <IRremote.h>

const int stepsPerRevolution = 20; // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define BTN1 6
#define BTN2 7
#define R 13
#define G 12
#define B 11
#define IR 10
#define KEY_LEFT 0X81B521EC
#define KEY_RIGHT 0X222F8310

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);
IRrecv irrecv(IR);
decode_results results;

unsigned long key_value = 0;

int prevIn1 = 0;
int prevIn2 = 0;

void setup()
{
  // set the speed at 5 rpm
  myStepper.setSpeed(1000);

  Serial.begin(115200);

  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  irrecv.enableIRIn();
  irrecv.blink13(false);
}

void loop()
{
  // 5C3B3C60
  int in1 = digitalRead(BTN1);
  int in2 = digitalRead(BTN2);
  // const
  // if (in1 != prevIn1 || in2 != prevIn2)
  // {
  // prevIn1 = in1;
  // prevIn2 = in2;
  // Serial.print("[ ");
  // Serial.print(in1);
  // Serial.print(" , ");
  // Serial.print(in2);
  // Serial.println(" ]");

  if (irrecv.decode(&results))
  {
    // unsigned long IRval = results.value;
    // results.value = 0;

    if (results.value == KEY_LEFT)
    {
      in1 = 1;
    }

    if (results.value == KEY_RIGHT)
    {
      in2 = 1;
    }
    Serial.println(results.value, HEX);
    irrecv.resume();
  }

  if (in1 != in2)
  {
    if (in1)
    {
      myStepper.step(stepsPerRevolution);
      digitalWrite(R, LOW);
      digitalWrite(B, LOW);
      digitalWrite(G, HIGH);
    }
    else
    {
      myStepper.step(-stepsPerRevolution);
      digitalWrite(R, LOW);
      digitalWrite(G, LOW);
      digitalWrite(B, HIGH);
    }
  }
  else
  {
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  }
}

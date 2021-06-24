#include<Servo.h>

int pos = 0;

Servo servo_5;
void setup()
{
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);

pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
servo_5.attach(5, 500, 2500);
}

void loop()
{
  /*
digitalWrite(11, HIGH);
digitalWrite(6, HIGH);

delay(1000); // Wait for 1000 millisecond(s)

digitalWrite(11, LOW);
digitalWrite(6, LOW);

delay(1000); // Wait for 1000 millisecond(s)

digitalWrite(10, HIGH);
digitalWrite(5, HIGH);

delay(1000); // Wait for 1000 millisecond(s)

digitalWrite(10, LOW);
digitalWrite(5, LOW);

delay(1000); // Wait for 1000 millisecond(s)
 */
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= 180; pos += 1) {
    // tell servo to go to position in variable 'pos'
    servo_5.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_5.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
  }
}
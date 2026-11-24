// Light tracker by Riley Gardner.

#include <Servo.h>

Servo tracker;

int angle = 90;
int tolerance = 30;  // Ignore small differences in light

void setup() {
  tracker.attach(9);
  tracker.write(angle);
}

void loop() {
  int leftLight = analogRead(A0);
  int rightLight = analogRead(A1);

  int difference = leftLight - rightLight;

  if (difference > tolerance) {
    angle = angle +1;
  }
  else if (difference < -tolerance) {
    angle = angle - 1;
  }

  angle = constrain(angle, 20, 160);
  tracker.write(angle);

  delay(30);
}
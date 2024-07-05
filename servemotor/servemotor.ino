#include <Servo.h>

#define SERVO_PIN_1 13
#define SERVO_PIN_2 12

int echo = 6;
int trig = 7;

Servo myservo1;
Servo myservo2;

int cnt = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo1.attach(SERVO_PIN_1);
  myservo2.attach(SERVO_PIN_2);
}

void loop() {
  digitalWrite(trig, LOW);  // Ensure the trigger pin is low
  delayMicroseconds(2);     // Let it settle
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  float distanceCM = ((34000.0 * duration) / 1000000) / 2.0;

  if (distanceCM <= 5) {
    if (cnt >= 10) {
      myservo1.write(170); // Increased by 10 degrees
      myservo2.write(70); // Apply same position to second servo
    } else {
      cnt += 2;
    }
  } else {
    if (cnt == 0) {
      myservo1.write(70); // Increased by 10 degrees
      myservo2.write(170); // Apply same position to second servo
    } else {
      cnt--;
    }
  }
  delay(70); // Reduced delay for faster response
}

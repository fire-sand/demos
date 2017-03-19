#include <Servo.h>

Servo servo;
int locked = 2;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  pinMode(locked, INPUT);
  servo.attach(9); // must use either pin 9 or 10 for servo library
}

void loop() {
  unlock();
  lock();
}

void unlock() {
  while (digitalRead(locked)) {
    servo.write(180);
  }
  servo.write(90);
  delay(1000);
  Serial.println("unlocked");
}

void lock() {
  while (!digitalRead(locked)) {
    servo.write(0);
  }
  servo.write(90);
  delay(1000);
  Serial.println("locked");
}


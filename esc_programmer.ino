#include <Servo.h>
#include <Bounce2.h>

Servo esc;
Bounce button;

void setup () {
  pinMode(7, INPUT_PULLUP);
  button.attach(7);
  button.interval(5);
  esc.attach(9);
  Serial.begin(9600);
}

void loop() {
  button.update();
  int v = button.read();
  if (v == LOW) {
    esc.write(MAX_PULSE_WIDTH-200);
    Serial.println(255);
  } else {
    esc.write(MIN_PULSE_WIDTH+200);
    Serial.println(0);
  }
}

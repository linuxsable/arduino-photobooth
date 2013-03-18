// Photobooth
// Author: Tyler

#define PIN_LED 7
#define PIN_SPEAKER 8
#define PIN_CAMERA 9
#define PIN_SENSOR 10

#include "pitches.h"

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_SPEAKER, OUTPUT);
  pinMode(PIN_CAMERA, OUTPUT);
  pinMode(PIN_SENSOR, OUTPUT);
}

void loop() {
  turnOffLED();
  
  for (int seconds = 0; seconds < 3; seconds++) {
     playTimerTone();
     delay(100);
     stopTimerTone();
     delay(800);
  }
  
  takePicture();
  turnOnLED();
  
  delay(5000);
}

void takePicture() {
  digitalWrite(PIN_CAMERA, HIGH);
  delay(50);
  digitalWrite(PIN_CAMERA, LOW);
}

void playTimerTone() {
  tone(PIN_SPEAKER, NOTE_B0);
}

void stopTimerTone() {
  noTone(PIN_SPEAKER);
}

void turnOnLED() {
  digitalWrite(PIN_LED, HIGH);
}

void turnOffLED() {
  digitalWrite(PIN_LED, LOW);
}

#define trigPin 13
#define echoPin 12
#define motor 6
#include "pitches.h"

const int buzzer = 9;
int distmotor;
float duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  distmotor = 0;
}

void loop() {

  // Write a pulse to the HC-SR04 Trigger Pin

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the response from the HC-SR04 Echo Pin

  duration = pulseIn(echoPin, HIGH);

  // Determine distance from duration
  // Use 343 metres per second as speed of sound

  distance = (duration / 2) * 0.0343;

  // Send results to Serial Monitor

  Serial.print("Distance = ");
  if (distance >= 40 || distance <= 2) {
    Serial.println("Out of range");
    distmotor = 0;


  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    distmotor = 1;
  }

  if (distmotor == 1) {
    for (int x=0; x<=9; x= x+1){
     analogWrite(6,0);
     delay(30); 
     analogWrite(6,60);
     delay(50);
     
      tone(9, NOTE_C4, 250);
      delay(300);
      noTone(9);
      
      tone(9, NOTE_G3, 125);
      delay(150);
      noTone(9);
      
      tone(9, NOTE_G3, 125);
      delay(150);
      noTone(9);
      
      tone(9, NOTE_A3, 250);
      delay(300);
      noTone(9);
      
      tone(9, NOTE_G3, 250);
      delay(300);
      noTone(9);
      
      tone(9, REST, 250);
      delay(300);
      noTone(9);
      
      tone(9, NOTE_B3, 250);
      delay(300);
      noTone(9);
      
      tone(9, NOTE_C4, 250);  
      delay(300);
      noTone(9);

    distmotor=0;
    }
    
    digitalWrite (6, LOW);
    noTone(buzzer);
    delay(5000);
    

  }
  else {
    digitalWrite (6, LOW);
    delay(500);
    noTone(buzzer);
    delay(500);
  }
  
  
}

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int knopGeel = 13;
int knopBlauw = 12;
int knopGroen = 11;
int knopRood = 10;
int knopWit = 9;
int ledGeel = 8;
int ledGroen = 6;
int ledRood = 7;
int ledBlauw = 5;
int knopStatusGeel = LOW;
int knopStatusBlauw = LOW;
int knopStatusGroen = LOW;
int knopStatusRood = LOW;
int knopStatusWit = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(knopGeel, INPUT);
  pinMode(knopBlauw, INPUT);
  pinMode(knopGroen, INPUT);
  pinMode(knopRood, INPUT);
  pinMode(knopWit, INPUT);
  pinMode(ledGeel, OUTPUT);
  pinMode(ledGroen, OUTPUT);
  pinMode(ledRood, OUTPUT);
  pinMode(ledBlauw, OUTPUT);
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  for (int i = 0; i < 10; i++) {
    lcd.print(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  knopStatusGeel = digitalRead(knopGeel);
  knopStatusBlauw = digitalRead(knopBlauw);
  knopStatusGroen = digitalRead(knopGroen);
  knopStatusRood = digitalRead(knopRood);
  knopStatusWit = digitalRead(knopWit);


  if (knopStatusGeel == HIGH) {
    digitalWrite(ledGeel, HIGH);
  } else {
    digitalWrite(ledGeel, LOW);
  }

  if (knopStatusBlauw == HIGH) {
    digitalWrite(ledBlauw, HIGH);
  } else {
    digitalWrite(ledBlauw, LOW);
  }

  if (knopStatusGroen == HIGH) {
    digitalWrite(ledGroen, HIGH);
  } else {
    digitalWrite(ledGroen, LOW);
  }

  if (knopStatusRood == HIGH) {
    digitalWrite(ledRood, HIGH);
  } else {
    digitalWrite(ledRood, LOW);
  }

 if (knopStatusWit == HIGH) {
    digitalWrite(ledGeel, HIGH);
  } else {
    digitalWrite(ledGeel, LOW);
  }


}

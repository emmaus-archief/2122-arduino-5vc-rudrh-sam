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
int positieSpelerY = 0;
int tijd = 0;
int gameStatus = 0;
int positieBlokX = 16;
int positieBlokY = random(2);
int tijdNu = 0;
int positieSpelerX = 0;
int gameStatusGameOver = 0;
float score = 0;



byte blok[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte speler[] = {
  B01110,
  B01111,
  B11101,
  B11111,
  B11110,
  B11110,
  B01010,
  B01010
};


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
  
}

void loop() {
  // put your main code here, to run repeatedly:
  knopStatusGeel = digitalRead(knopGeel);
  knopStatusBlauw = digitalRead(knopBlauw);
  knopStatusGroen = digitalRead(knopGroen);
  knopStatusRood = digitalRead(knopRood);
  knopStatusWit = digitalRead(knopWit);

  tijd = millis();
 

  if (gameStatus < 0 & knopStatusWit == HIGH) {
  lcd.setCursor(0, 0);          
  lcd.print("Press White");
  lcd.setCursor(0, 1);    
  lcd.print("Button To Start");  
  }

  if(gameStatus > 0 & gameStatusGameOver == 0) {
  lcd.setCursor(12, 0);          
  lcd.print(round(score));  
  score = score + 0.2;
  }

  if(gameStatusGameOver > 0) {
  lcd.setCursor(12, 0);          
  lcd.print(round(score));  
  }

  if(knopStatusWit == HIGH) {
  gameStatus = gameStatus + 1;
  }

  if(gameStatus > 0 & gameStatusGameOver == 0) {
   lcd.begin(16, 2);
   lcd.createChar(1, blok);
   lcd.setCursor(positieBlokX, positieBlokY);
   lcd.write(1);
  }

  if(tijd > tijdNu + 400 & gameStatus > 1 & gameStatusGameOver == 0) {
    positieBlokX  = positieBlokX - 1;
    tijdNu = millis();
  }

  if(positieBlokX < 0) {
    positieBlokX = positieBlokX + 16;
    positieBlokY = random(2);
  }

  if(positieBlokX == positieSpelerX & positieBlokY == positieSpelerY || gameStatusGameOver > 0) {
  gameStatusGameOver = gameStatusGameOver + 1;
  lcd.setCursor(0, 0);          
  lcd.print("Game Over");  
  }

  if(gameStatusGameOver > 0 & knopStatusWit == HIGH) {
    gameStatusGameOver = 0;
    gameStatus = 0;
    score = 0;
    positieBlokX = 16;
  }

  if(gameStatus > 0 & gameStatusGameOver == 0) {
   lcd.begin(16, 2);
   lcd.createChar(1, speler);
   lcd.setCursor(positieSpelerX, positieSpelerY);
   lcd.write(1);
  } 
  
    if (knopStatusWit == HIGH & positieSpelerY == 1) {
    positieSpelerY = positieSpelerY - 1;
  } else if (knopStatusWit == HIGH & positieSpelerY == 0) {
    positieSpelerY = positieSpelerY + 1;
  }


  


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

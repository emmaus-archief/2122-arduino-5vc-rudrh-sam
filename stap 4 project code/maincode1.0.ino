// dit is om de display te laten werken
#include <Wire.h>
#include "rgb_lcd.h"

// dit is om de display te laten werken
rgb_lcd lcd;

// digital pins van de knoppen
int knopGeel = 13;
int knopBlauw = 12;
int knopGroen = 11;
int knopRood = 10;
int knopWit = 9;

// digital pins van de LED's
int ledGeel = 8;
int ledGroen = 6;
int ledRood = 7;
int ledBlauw = 5;

// status van de knoppen
int knopStatusGeel = LOW;
int knopStatusBlauw = LOW;
int knopStatusGroen = LOW;
int knopStatusRood = LOW;
int knopStatusWit = LOW;

// status van de LED's
int ledStatusGeel = LOW;
int ledStatusBlauw = LOW;
int ledStatusGroen = LOW;
int ledStatusRood = LOW;

//positie van speler en zijn wapen
int positieSpelerX = 0;
int positieSpelerY = 0;
int kamehamehaX = 1;
int positieSpelerBovenY = 0;
int positieSpelerOnderY = 1;

// positie van de obstakels en, als ze het hebben, wapens
int positieRechthoekX = 16;
int positieRechthoekY = random(2);

int positieVierkantX = 22;
int positieVierkantBovenY = 0;
int positieVierkantOnderY = 1;

int positieVaderX = 28;
int positieVaderBovenY = 0;
int positieVaderOnderY = 1;
int positieZwaardAchterX = positieVaderX - 1;
int positieZwaardVoorX = positieVaderX - 2;
    
int positieDriehoekX = 34;
int positieDriehoekBovenY = 0;
int positieDriehoekOnderY = 1;

int positieVijandX = 40;
int positieVijandBovenY = 0;
int positieVijandOnderY = 1;
int positieBlastAchterX =  positieVijandX - 1;
int positieBlastVoorX =  positieVijandX - 2;

// array om de obstakels random posities te geven
int positieRandom[] = {16, 22, 28, 34, 40};
int positieRandom2[] = {16, 22, 28, 34, 40};

// variabele voor de tijd
unsigned long tijd = 0;
unsigned long tijdNu = 0;
unsigned long tijdAftelling = 0;
unsigned long tijdPagina = 0;
unsigned long tijdGameMode = 0;
unsigned long tijdHart = 0;
unsigned long tijdRegels = 0;
unsigned long tijdLed = 0;


// gamestatussen
const int STARTSCHERM = 0;
const int REGELS = 1;
const int HERHALING = 2;
const int GAMEMODE = 3;
const int SPELLADING = 4;
const int SPELEN = 5;
const int OBSTAKEL = 6;
const int GAMEOVER = 7;
int gameStatus = STARTSCHERM;

// gamemodestatussen
const int EASY = 0;
const int NORMAL = 1;
const int HARD = 2;
int gameModeStatus = EASY;

// variabele voor de hartjes en score
float score = 0;
float hartjes = 0;

// getal waar de aftelling mee begint
int aftelling = 4;

// getal voor welke pagina van de regels je bent
int regelPagina = 0;

// getal voor welke pagina binnen een regel je bent
int regels = 0;

// getal voor welke gamemode er wordt laten zien
int gameMode = 0;

// variabele voor wanneer de obstakels mogen bewegen
int bewegen = 5;

// status van de knoppen
const int knopEerst = 0;
const int knopDaarna = 1;
int knopStatus = 0;

// de bytes voor de objecten die laten zien worden
byte rechthoek[] = {
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
  B00000,
  B00000,
  B11100,
  B11000,
  B11100,
  B11101,
  B10100,
  B10100
};

byte kamehameha[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000
};


byte vierkantBoven[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11111
};

byte vierkantOnder[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000
};

byte driehoekBoven[] = {
  B00000,
  B00000,
  B00000,
  B00001,
  B00011,
  B00111,
  B01111,
  B11111
};

byte driehoekOnder[] = {
  B11111,
  B01111,
  B00111,
  B00011,
  B00001,
  B00000,
  B00000,
  B00000
};

byte vijandLichaamBoven[] = {
  B11111,
  B10111,
  B10111,
  B11111,
  B01110,
  B01110,
  B01110,
  B01110
};

byte vijandLichaamOnder[] = {
  B01110,
  B01110,
  B01110,
  B01110,
  B01110,
  B11111,
  B11011,
  B11011
};

byte blastAchter[] = {
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111
};

byte blastVoor[] = {
  B00000,
  B00111,
  B01111,
  B11111,
  B11111,
  B01111,
  B00111,
  B00000
};

byte spelerBoven[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B01110,
  B01111,
  B11101,
  B11111
};

byte spelerOnder[] = {
  B11110,
  B11110,
  B01010,
  B01010,
  B00000,
  B00000,
  B00000,
  B00000
};

byte vaderOnder[] = {
  B01111,
  B01111,
  B01111,
  B01011,
  B01010,
  B01010,
  B01010,
  B01010
};

byte vaderBoven[] = {
  B01110,
  B11110,
  B10110,
  B11111,
  B11111,
  B01111,
  B01111,
  B01111
};

byte zwaardAchter[] = {
  B00000,
  B11000,
  B11000,
  B11111,
  B11111,
  B11000,
  B11000,
  B00000
};

byte zwaardVoor[] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000
};

byte hart[] = {
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100
};


// functie die ervoor zorgt dat een object teruggeplaatst wordt als het van het scherm gaat. 
int positieObjecten (int positieObject) {
    if (positieObject < 0) {
       positieObject = 39;
       bewegen = bewegen - 1;
    }
    
    if (bewegen == 0) {
       positieObject = 39;
       positieRechthoekY = random(2);
       bewegen = 5;
    }
    return positieObject;
  }

// deze functie vult een random waarde in de array in waardoor het object iedere keer en andere waarde uit de array krijgt, hierdoor is het randomised, maar wel met vaste intervallen.
int randomPosities (int positieObjectX) {
    int x = random(5);
    if (positieRandom[x] > -1) {
       positieObjectX = positieRandom[x];
       positieRandom[x] = -1;
    }
    if (positieRandom[0] == -1 & positieRandom[1] == -1 &  positieRandom[2] == -1 &  positieRandom[3] == -1 & positieRandom[4] == -1) {
       positieRandom[0] = positieRandom2[0];
       positieRandom[1] = positieRandom2[1];
       positieRandom[2] = positieRandom2[2];
       positieRandom[3] = positieRandom2[3];
       positieRandom[4] = positieRandom2[4];
    }
    return positieObjectX;
};


void setup() {
// pinmodes van de knoppen en LED's
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
// leest gelijk de status van de knoppen en LED's
  knopStatusGeel = digitalRead(knopGeel);
  knopStatusBlauw = digitalRead(knopBlauw);
  knopStatusGroen = digitalRead(knopGroen);
  knopStatusRood = digitalRead(knopRood);
  knopStatusWit = digitalRead(knopWit);
  ledStatusGeel = digitalRead(ledGeel);
  ledStatusBlauw = digitalRead(ledBlauw);
  ledStatusGroen = digitalRead(ledGroen);
  ledStatusRood = digitalRead(ledRood);

// geeft tijd dezelfde waarde als wannneer de arduino is gestart
  tijd = millis();

// hierin staat er wat er op het scherm gebeurd als startscherm er is, na een bepaalde tijd kan je naar de volgende pagina
  if (gameStatus == STARTSCHERM) {
     lcd.begin(16, 2);
     lcd.setCursor(0, 0);
     lcd.print("Press White");
     lcd.setCursor(0, 1);
     lcd.print("To Start");
    if(tijd > tijdPagina + 500) {
       regelPagina = 0;
    }
    if (knopStatusWit == HIGH & regelPagina == 0) {
       gameStatus = REGELS;
       tijdPagina = tijd;
       tijdRegels = tijd;
    } 
 }

// hierin staat wat regel 1 is
  if (gameStatus == REGELS) {
      if(regelPagina == 0) {
         if(regels == 0) {
            lcd.begin(16, 2);
            lcd.createChar(1, rechthoek);
            lcd.setCursor(14, 1);
            lcd.write(1);
            lcd.setCursor(0, 0);
            lcd.print("Press White");
            lcd.setCursor(0, 1);
            lcd.print("For:");
            if(tijd > tijdRegels + 2500){
               tijdRegels = tijd;
               regels = 1;
            } 
         } 
         if (regels == 1){
            lcd.begin(16, 2);
            lcd.setCursor(0, 0);
            lcd.print("Press White");
            lcd.setCursor(0, 1);
            lcd.print("To Continue");
            if(tijd > tijdRegels + 2500){
              tijdRegels = tijd;
              regels = 0;
            }    
        }
         if (tijd > tijdPagina + 500) {   
            if (knopStatusWit == HIGH) {
               regelPagina = 1;
               tijdPagina = tijd;  
               regels = 0;
               tijdRegels = tijd;
            }
        }
    }
 
// hierin staat wat regel 2 is
      if (regelPagina == 1) {
         if (regels == 0){
            lcd.begin(16, 2);
            lcd.createChar(1, vierkantBoven);
            lcd.setCursor(14, 0);
            lcd.write(1);
            lcd.createChar(2, vierkantOnder);
            lcd.setCursor(14, 1);
            lcd.write(2);
            lcd.setCursor(0, 0);
            lcd.print("Press Yellow");
            lcd.setCursor(0, 1);
            lcd.print("For:");
            if(tijd > tijdRegels + 2500){
              tijdRegels = tijd;
              regels = 1;
            }
        }
         if (regels == 1){
            lcd.begin(16, 2);
            lcd.setCursor(0, 0);
            lcd.print("Press White");
            lcd.setCursor(0, 1);
            lcd.print("To Continue");
            if (tijd > tijdRegels + 2500){
               tijdRegels = tijd;
               regels = 0;
           }
        }
         if (tijd > tijdPagina + 500) {
            if (knopStatusWit == HIGH) {
               regelPagina = 2;
               tijdPagina = tijd;  
               regels = 0;   
               tijdRegels = tijd;
            }
         }
      }

// hierin staat wat regel 3 is
     if (regelPagina == 2) {
        if (regels == 0) {
           lcd.begin(16, 2);
           lcd.createChar(1, vaderOnder);
           lcd.setCursor(14, 1);
           lcd.write(1);
           lcd.createChar(2, vaderBoven);
           lcd.setCursor(14, 0);
           lcd.write(2);
           lcd.createChar(3, zwaardAchter);
           lcd.setCursor(13, 0);
           lcd.write(3);
           lcd.createChar(4, zwaardVoor);
           lcd.setCursor(12, 0);
           lcd.write(4);
           lcd.setCursor(0, 0);
           lcd.print("Press Blue");
           lcd.setCursor(0, 1);
           lcd.print("To Shoot:");
           if (tijd > tijdRegels + 2500){
              tijdRegels = tijd;
              regels = 1;   
          }
       }  
       if (regels == 1){
           lcd.begin(16, 2);
           lcd.setCursor(0, 0);
           lcd.print("Press White");
           lcd.setCursor(0, 1);
           lcd.print("To Continue");
           if (tijd > tijdRegels + 2500){
              tijdRegels = tijd;
              regels = 0;
           }
      }

       if (tijd > tijdPagina + 500) {
          if (knopStatusWit == HIGH) {
             regelPagina = 3;
             tijdPagina = tijd;     
             regels = 0;
             tijdRegels = tijd;
          }
       }
    }
   
// hierin staat wat regel 4 is
     if (regelPagina == 3) {
        if (regels == 0) {
           lcd.begin(16, 2);
           lcd.createChar(1, driehoekBoven);
           lcd.setCursor(14, 0);
           lcd.write(1);
           lcd.createChar(2, driehoekOnder);
           lcd.setCursor(14, 1);
           lcd.write(2);
           lcd.setCursor(0, 0);
           lcd.print("Press Green");
           lcd.setCursor(0, 1);
           lcd.print("For:");
           if (tijd > tijdRegels + 2500){
              tijdRegels = tijd;
              regels = 1;
           }
        }
        if (regels == 1){
           lcd.begin(16, 2);
           lcd.setCursor(0, 0);
           lcd.print("The Triangle");
           lcd.setCursor(0, 1);
           lcd.print("Gives Hearts");
           if (tijd > tijdRegels + 2500){
              tijdRegels = tijd;
              regels = 2;
           }    
       }
       if (regels == 2){
          lcd.begin(16, 2);
          lcd.setCursor(0, 0);
          lcd.print("Press White");
          lcd.setCursor(0, 1);
          lcd.print("To Continue");
          if (tijd > tijdRegels + 2500){
             tijdRegels = tijd;
             regels = 0;
          }
       }
       if (tijd > tijdPagina + 500) {
          if (knopStatusWit == HIGH) {
             regelPagina = 4;
             tijdPagina = tijd;     
             regels = 0;
             tijdRegels = tijd;
          }
       }
    }

// hierin staat wat regel 5 is
     if (regelPagina == 4) {
        if (regels == 0) {
           lcd.begin(16, 2);
           lcd.createChar(1, vijandLichaamBoven);
           lcd.setCursor(14, 0);
           lcd.write(1);
           lcd.createChar(2, vijandLichaamOnder);
           lcd.setCursor(14, 1);
           lcd.write(2);
           lcd.createChar(3, blastAchter);
           lcd.setCursor(13, 1);
           lcd.write(3);
           lcd.createChar(3, blastAchter);
           lcd.setCursor(13, 0);
           lcd.write(3);
           lcd.createChar(4, blastVoor);
           lcd.setCursor(12, 0);
           lcd.write(4);
           lcd.createChar(4, blastVoor);
           lcd.setCursor(12, 1);
           lcd.write(4);
           lcd.setCursor(0, 0);
           lcd.print("Press Red");
           lcd.setCursor(0, 1);
           lcd.print("To Shoot:");
           if (tijd > tijdRegels + 2500){
              tijdRegels = tijd;
              regels = 1;
           }
        }
        if (regels == 1){
           lcd.begin(16, 2);
           lcd.setCursor(0, 0);
           lcd.print("Press White");
           lcd.setCursor(0, 1);
           lcd.print("To Continue");
           if (tijd > tijdRegels + 2500){
              tijdRegels = tijd;
              regels = 0;
          }
       }
       if (tijd > tijdPagina + 500) {
          if (knopStatusWit == HIGH) {
             gameStatus = HERHALING;
             tijdPagina = tijd;
             regels = 0;
             tijdRegels = tijd;
          }
       }
    }
 }

// hierin staat dat je met de gele knop weer terug kan gaan en de regels opnieuw zien of je gaat verder
  if (gameStatus == HERHALING) {
     lcd.begin(16, 2);
     lcd.setCursor(0, 0);
     lcd.print("Press Yellow");
     lcd.setCursor(0, 1);
     lcd.print("Button To Repeat");
     if (knopStatusGeel == HIGH){
        gameStatus = REGELS;
        regelPagina = 0;
        regels = 0;
        tijdRegels = tijd;
     }
     if (tijd > tijdPagina + 500) {
        if (knopStatusWit == HIGH) {
           gameStatus = GAMEMODE;
           tijdGameMode = tijd;
           regels = 0;
        }
     }
  }

// hierin worden de gamemodes laten zien in een bepaalde tijd
  if (gameStatus == GAMEMODE) {
     if (gameMode == 0) {
        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("Press Green For");
        lcd.setCursor(0, 1);
        lcd.print("Easy Mode");
        if (tijd > tijdGameMode + 3000) {
           gameMode = 1;
           tijdGameMode = tijd;
        }
    } 
    if (gameMode == 1) {
       lcd.begin(16, 2);
       lcd.setCursor(0, 0);
       lcd.print("Press Yellow For");
       lcd.setCursor(0, 1);
       lcd.print("Normal Mode");
       if (tijd > tijdGameMode + 3000) {
          gameMode = 2;
          tijdGameMode = tijd;
       }
    } 
    if (gameMode == 2) {
       lcd.begin(16, 2);
       lcd.setCursor(0, 0);
       lcd.print("Press Red For");
       lcd.setCursor(0, 1);
       lcd.print("Hard Mode");
       if (tijd > tijdGameMode + 3000) {
          gameMode = 0;
          tijdGameMode = tijd;
       }
    } 
    if (knopStatusGroen == HIGH) {
       gameStatus = SPELLADING;
       gameModeStatus = EASY;
    }
    if (knopStatusGeel == HIGH) {
       gameStatus = SPELLADING;
       gameModeStatus = NORMAL;
    }
    if (knopStatusRood == HIGH) {
       gameStatus = SPELLADING;
       gameModeStatus = HARD;
    }
 }

// hierin wordt gezegd dat het spel in 3 seconde gaat starten
  if (gameStatus == SPELLADING) {
     lcd.begin(16, 2);
     lcd.setCursor(0, 0);
     lcd.print("GAME STARTING");
     lcd.setCursor(0, 1);
     lcd.print("IN    SECONDS");
     lcd.setCursor(3, 1);
     lcd.print(aftelling);

     if (tijd > tijdAftelling + 1000) {
        aftelling = aftelling - 1;
        tijdAftelling = tijd;
     }
     if (aftelling < 1) {
        gameStatus = SPELEN;
     }
  }

// hierin wordt gezegd wat er gebeurd als gamestatus spelen is
  if (gameStatus == SPELEN) {
     lcd.begin(16, 2);
     lcd.createChar(1, speler);
     lcd.setCursor(positieSpelerX, positieSpelerY);
     lcd.write(1);

     lcd.createChar(2, kamehameha);
     lcd.setCursor(kamehamehaX, positieSpelerY);
     lcd.write(2);

// als LED rood of blauw aan is, beweegt de kamehameha
     if ((ledStatusRood == HIGH || ledStatusBlauw == HIGH) & kamehamehaX < 17) {
        kamehamehaX = kamehamehaX + 1;
        delay(100);
     }  else if (ledStatusRood == LOW || ledStatusBlauw == LOW || kamehamehaX > 16) {
                kamehamehaX = 1;
        }

// als knop wit is ingedrukt gaat de speler naar beneden of boven
     if (knopStatusWit == HIGH & positieSpelerY == 1) {
        positieSpelerY = positieSpelerY - 1;
        delay(100);
     }  else if (knopStatusWit == HIGH & positieSpelerY == 0) {
                positieSpelerY = positieSpelerY + 1;
                delay(100);
        }

// als knop geel of groen ingedrukt is gaat de gamestatus naar obstakel
     if (knopStatusGeel == HIGH || knopStatusGroen == HIGH) {
        gameStatus = OBSTAKEL;
     }  

// als je geraakt wordt in een bepaalde tijd gaat een hartje af en als die kleiner dan 0 is ga je doodt
     if ((positieRechthoekX == positieSpelerX & positieRechthoekY == positieSpelerY || positieVierkantX == positieSpelerX || positieZwaardVoorX == positieSpelerX  || positieBlastVoorX == positieSpelerX) & tijd > tijdHart + 1000) {
        hartjes = hartjes - 1;
        tijdHart = tijd;
     }    
     if ((positieRechthoekX == positieSpelerX & positieRechthoekY == positieSpelerY || positieVierkantX == positieSpelerX || positieZwaardVoorX == positieSpelerX  || positieBlastVoorX == positieSpelerX) & hartjes < 0) {
        gameStatus = GAMEOVER;
     }
  
  }

// hierin wordt gezegd wat er in gamestatus spelen en obstakel gebeurd
  if (gameStatus == SPELEN || gameStatus == OBSTAKEL) {
     lcd.begin(16, 2);
     lcd.setCursor(12, 0);
     lcd.print(round(score));
     score = score + 0.2;
    
     lcd.createChar(1, hart);
     lcd.setCursor(3, 0);
     lcd.write(1);    
     lcd.setCursor(2, 0);
     lcd.print(round(hartjes));

// postie van de wapens van de obstakels
    positieZwaardAchterX = positieVaderX - 1;
    positieZwaardVoorX = positieVaderX - 2;
    positieBlastAchterX =  positieVijandX - 1;
    positieBlastVoorX =  positieVijandX - 2;

// dit zegt als de objecten samen een x van 190 of hoger heeft dan krijgen ze een nieuwe random x en ze kunnen ook weer bewegen
  if (positieRechthoekX +  positieVierkantX + positieVaderX + positieDriehoekX + positieVijandX  >= 190) {
     positieRechthoekX = randomPosities(positieRechthoekX);
     positieVierkantX = randomPosities(positieVierkantX);
     positieVaderX = randomPosities(positieVaderX);
     positieDriehoekX = randomPosities(positieDriehoekX);
     positieVijandX = randomPosities(positieVijandX);
  }
                            
// dit maakt de obstakels
     lcd.createChar(2, rechthoek);
     lcd.setCursor(positieRechthoekX, positieRechthoekY);
     lcd.write(2);

     lcd.createChar(3, vierkantBoven);
     lcd.setCursor(positieVierkantX, positieVierkantBovenY);
     lcd.write(3);

     lcd.createChar(5, vierkantOnder);
     lcd.setCursor(positieVierkantX, positieVierkantOnderY);
     lcd.write(5); 

     lcd.createChar(6, vaderBoven);
     lcd.setCursor(positieVaderX, positieVaderBovenY);
     lcd.write(6);

     lcd.createChar(7, vaderOnder);
     lcd.setCursor(positieVaderX, positieVaderOnderY);
     lcd.write(7);

     lcd.createChar(8, zwaardAchter);
     lcd.setCursor(positieZwaardAchterX, positieVaderBovenY);
     lcd.write(8);
    
     lcd.createChar(9, zwaardVoor);
     lcd.setCursor(positieZwaardVoorX, positieVaderBovenY);
     lcd.write(9);

// nog een keer lcd.begin, want de arduino heeft niet genoeg plek om meer bytes op te slaan
     lcd.begin(16, 2);
     lcd.createChar(1, driehoekBoven);
     lcd.setCursor(positieDriehoekX, positieDriehoekBovenY);
     lcd.write(1); 

     lcd.createChar(2, driehoekOnder);
     lcd.setCursor(positieDriehoekX, positieDriehoekOnderY);
     lcd.write(2);

     lcd.createChar(3, vijandLichaamBoven);
     lcd.setCursor(positieVijandX, positieVijandBovenY);
     lcd.write(3);

     lcd.createChar(4, vijandLichaamOnder);
     lcd.setCursor(positieVijandX, positieVijandOnderY);
     lcd.write(4);

     lcd.createChar(5, blastAchter);
     lcd.setCursor(positieBlastAchterX, positieVijandOnderY);
     lcd.write(5);

     lcd.setCursor(positieBlastAchterX, positieVijandBovenY);
     lcd.write(5);

     lcd.createChar(6, blastVoor);
     lcd.setCursor(positieBlastVoorX, positieVijandOnderY);
     lcd.write(6);

     lcd.setCursor(positieBlastVoorX, positieVijandBovenY);
     lcd.write(6);


// dit laat zien hoe snel een obstakel en bij welke gamemode het beweegt
    if ((tijd > tijdNu + 500 & gameModeStatus == EASY || tijd > tijdNu + 350 & gameModeStatus == NORMAL || tijd > tijdNu + 200 & gameModeStatus == HARD) & bewegen > 0){
       positieRechthoekX  = positieRechthoekX - 1;
       positieVierkantX = positieVierkantX - 1;
       positieVaderX = positieVaderX - 1;
       positieDriehoekX = positieDriehoekX - 1;
       positieVijandX = positieVijandX - 1;
       tijdNu = millis();
    }

// dit zegt als de kamehameha(blast die de speler schiet) gelijk is aan vijand of vader, dan gaan ze dood
    if (kamehamehaX == positieVijandX & ledStatusRood == HIGH) {
        positieVijandX = -1;
    }

    if (kamehamehaX == positieVaderX & ledStatusBlauw == HIGH) {
       positieVaderX = -1;
    }

// dit zorgt ervoor dat de functie positieobjecten in de loop is
    positieVaderX = positieObjecten(positieVaderX);
    positieDriehoekX = positieObjecten(positieDriehoekX);
    positieVierkantX = positieObjecten(positieVierkantX);
    positieRechthoekX = positieObjecten(positieRechthoekX);
    positieVijandX = positieObjecten(positieVijandX);

// dit zegt dat de LED aan gaat bij een bepaalde tijd en als de bijbehorende knop wordt ingedrukt 
   if (digitalRead(knopGeel) == HIGH & knopStatus == knopEerst & tijd > tijdLed + 300) {
      digitalWrite(ledGeel, HIGH);
      tijdLed = tijd;
      knopStatus = knopDaarna;
   } 
   if (digitalRead(knopBlauw) == HIGH & knopStatus == knopEerst & tijd > tijdLed + 300) {
      digitalWrite(ledBlauw, HIGH);
      tijdLed = tijd;
      knopStatus = knopDaarna;
   } 
   if (digitalRead(knopGroen) == HIGH & knopStatus == knopEerst & tijd > tijdLed + 300) {
      digitalWrite(ledGroen, HIGH);
      tijdLed = tijd;
      knopStatus = knopDaarna;
   } 
   if (digitalRead(knopRood) == HIGH & knopStatus == knopEerst & tijd > tijdLed + 300) {
      digitalWrite(ledRood, HIGH);
      tijdLed = tijd;
      knopStatus = knopDaarna;
   }

// dit zegt dat de knop uit gaat na een bepaalde tijd of als je de bijbehorende knop weer indrukt
   if (tijd > tijdLed + 1500 || digitalRead(knopGeel) == HIGH) {
      if (digitalRead(ledGeel) == HIGH & knopStatus == knopDaarna & tijd > tijdLed + 300) {
         digitalWrite(ledGeel, LOW);
         tijdLed = tijd; 
         knopStatus = knopEerst;
      }
   }
      
   if (tijd > tijdLed + 1500 || digitalRead(knopGroen) == HIGH) {
      if (digitalRead(ledGroen) == HIGH & knopStatus == knopDaarna & tijd > tijdLed + 300) {
         digitalWrite(ledGroen, LOW);
         tijdLed = tijd;
         knopStatus = knopEerst;
      }
   }
    
   if (tijd > tijdLed + 1300 || digitalRead(knopBlauw) == HIGH) {
      if (digitalRead(ledBlauw) == HIGH & knopStatus == knopDaarna & tijd > tijdLed + 300) {
         digitalWrite(ledBlauw, LOW);
         tijdLed = tijd;
         knopStatus = knopEerst;
      }
   }
    
   if (tijd > tijdLed + 1300 || digitalRead(knopRood) == HIGH) {
      if (digitalRead(ledRood) == HIGH & knopStatus == knopDaarna & tijd > tijdLed + 300) {
         digitalWrite(ledRood, LOW);
         tijdLed = tijd;
         knopStatus = knopEerst;
      }
    }
  }
    
// hierin wordt beschreven wat bij gamestatus obstakel gebeurd
  if (gameStatus == OBSTAKEL) {
     lcd.begin(16, 2);
     lcd.createChar(1, spelerBoven);
     lcd.setCursor(positieSpelerX, positieSpelerBovenY);
     lcd.write(1);

     lcd.createChar(2, spelerOnder);
     lcd.setCursor(positieSpelerX, positieSpelerOnderY);
     lcd.write(2);

// dit zegt dat er 1 hartje bij komt per driehoek
     if (ledStatusGroen == HIGH & positieSpelerX == positieDriehoekX & tijd > tijdHart + 1500) {
        hartjes = hartjes + 1;
        tijdHart = tijd;
     }

// als LED geel of groen uit zijn, gaat de gamestatus naar spelen
     if (ledStatusGeel == LOW & ledStatusGroen == LOW) {
        gameStatus = SPELEN; 
     }
    
// als je geraakt wordt in een bepaalde tijd gaat een hartje af en als die kleiner dan 0 is ga je doodt
     if ((positieRechthoekX == positieSpelerX || positieVierkantX == positieSpelerX & ledStatusGeel == LOW || positieZwaardVoorX == positieSpelerX || positieBlastVoorX == positieSpelerX) & tijd > tijdHart + 1000) {
        hartjes = hartjes - 1;
        tijdHart = tijd;
     }  
     if ((positieRechthoekX == positieSpelerX || positieVierkantX == positieSpelerX & ledStatusGeel == LOW || positieZwaardVoorX == positieSpelerX || positieBlastVoorX == positieSpelerX) & hartjes < 0) {
        gameStatus = GAMEOVER;
     }
  
  

 }



// hierin wordt gezegd wat er bij gamestatus gameover gebeurd
  if (gameStatus == GAMEOVER) {
      lcd.begin(16, 2);
      lcd.setCursor(12, 0);
      lcd.print(round(score));
      lcd.setCursor(0, 0);
      lcd.print("Game Over");

// als de witte knop is ingedrukt, ga je naar gamestatus startscherm en variabelen worden teruggezet om het spel werkend te maken na gameover    
      if (knopStatusWit == HIGH) {
         gameStatus = STARTSCHERM;
         score = 0;
         hartjes = 0;
         regelPagina = -1;
         tijdPagina = tijd;
         aftelling = 4;
         positieRechthoekX = 16;
         positieVierkantX = 22;
         positieVaderX = 28;
         positieDriehoekX = 36;
         positieVijandX = 40;
         positieZwaardAchterX = positieVaderX - 1;
         positieZwaardVoorX = positieVaderX - 2;
         positieBlastAchterX =  positieVijandX - 1;
         positieBlastVoorX =  positieVijandX - 2;
         bewegen = 5;
         knopStatus = knopEerst;
         digitalWrite(ledGeel, LOW);
         digitalWrite(ledBlauw, LOW);
         digitalWrite(ledGroen, LOW);
         digitalWrite(ledRood, LOW);
     }
   }
 }

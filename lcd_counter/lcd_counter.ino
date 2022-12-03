// Arduino Projects - by J4ckris ;)
/*
Materials:
  - lcd display
  - 1 led
  - 2 resistence
  - jumpers
  - ultrasonic sensor

*/

#include <LiquidCrystal.h> // Library to use lcd


//variables
int rs = 7;
int e = 6;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

int trig = 10;
int echo = 9;
int traveltime;

int counter = 0; 

int led = 11;

int counter_v;

// define the pins and put it here with there varibles
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup(){

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);

  lcd.begin(16,2); // define dimensions of the lcd

}

void loop(){

  int var= 0;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  traveltime = pulseIn(echo, HIGH);

  if (traveltime < 1000){ // Detects movement from 0 meters to 1 meter

    if (var == 0){

      
      counter++;
      digitalWrite(led, HIGH);


      lcd.setCursor(0,0);
      lcd.print("Movement");
      

      lcd.setCursor(4,2);
      lcd.print("Detected !!");

      delay(500);
      lcd.clear();

      if(counter > 1){
                
        counter_v++;
        counter = 0;
        delay(1000);


      }

    }
    
  } else {

    digitalWrite(led, LOW);

    lcd.setCursor(0,0);
    lcd.print("No Movement ");

    lcd.setCursor(4, 2);
    lcd.print("Counter :");
    lcd.print(counter_v);

    delay(500);
    lcd.clear();

  }

}

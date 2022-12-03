/* Arduino Projects - by j4ckris ;)

Materials:

  - lcd display
  - 2 resistence
  - Ultasonic sensor
  - Jumpers
  - Potenciometer
  - 1 led
  - 
*/


#include <LiquidCrystal.h>
int rs = 7;
int e = 6;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;

int trig = 10;
int echo = 9;
int traveltime, distance;

int led = 11;


LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

void setup(){

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  lcd.begin(16,2);

}

void loop(){

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  traveltime = pulseIn(echo, HIGH);
  distance = (traveltime/2)/25.19;
  
  lcd.setCursor(0,0);
  lcd.print("Distance : ");
  
  lcd.print(distance);
  lcd.print(" CM");
  delay(500);
  lcd.clear();
}

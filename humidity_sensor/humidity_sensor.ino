/* Arduino Projects - by j4ckriss :}

  - humidity sensor
  - lcd 16x2
  - potenciometer
  - 1 toggle butoon
  - 2 resistence
  - jumpers

*/
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

//LCD
int rs = 9;
int e = 8;
int d4 = 10;
int d5 = 11;
int d6 = 12;
int d7 = 13;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
#define Type DHT11

int dhtpin = 2;

DHT HT(dhtpin, Type);

int humidity;
float tempCel;
float tempF;
int dot = 100;
//----




//button
int button_value;

//

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  lcd.begin(16, 2);
  pinMode(4, INPUT);

}

void celcius(){
  //Celcius display

  humidity = HT.readHumidity();
  tempCel = HT.readTemperature();
  tempF = HT.readTemperature(true);
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempCel);
  lcd.println(" *C  ");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.println("%   ");

  delay(dot);
  lcd.clear();

}

void farenheith(){
  // Farenheith display
  humidity = HT.readHumidity();
  tempCel = HT.readTemperature();
  tempF = HT.readTemperature(true);
  
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempF);
  lcd.println(" *F  ");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.println("%   ");

  delay(dot);
  lcd.clear();
  
}

void loop() {
  // put your main code here, to run repeatedly:

  button_value = digitalRead(A0);
  
  if (button_value == 0){
    
    farenheith();

  } else {

    celcius();

  }
  
}

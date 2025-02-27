#include <LiquidCrystal.h>
#include <Servo.h>

// Ultrasonic Sensor Defined
const int trig = 2;
const int echo = 3;

int traveltime, distance;

// Counter and Cars Variables
int cars_var;

// Threshold
const int upperThreshold = 6; // Upper threshold (in cm) for object detected
const int lowerThreshold = 2; // Lower threshold (in cm) for object not detected

// Servo Motor Pin
const int servoPin = 24;

// lcd
int rs = 13;
int e = 12;
int d4 = 10;
int d5 = 9;
int d6 = 8;
int d7 = 7;

LiquidCrystal lcd(rs, e, d4, d5, d6, d7);
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  myservo.attach(servoPin);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome to :}");
  lcd.setCursor(0, 1);
  lcd.print(" The Parking Lot");

  delay(2000);
  
  Serial.begin(9600);
  Serial.println("Init");

}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  int traveltime = pulseIn(echo, HIGH);
  int distance = traveltime * 0.034 / 2; // Convert travel time to cm

  if (distance <= upperThreshold && distance >= lowerThreshold) {
    
    Serial.println("Opening...");
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Opening Gateway");
    lcd.setCursor(0, 1);
    lcd.print("...");

    cars_var++;
    myservo.write(90);

    delay(3000);

  } else {
    
    Serial.print("Cars inside: ");
    Serial.print(cars_var);
    Serial.println("");
        
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Welcome :}");
    lcd.setCursor(0, 1);
    lcd.print("Cars Inside: ");
    lcd.print(cars_var);

    myservo.write(180); 
    delay(300);

  }
}

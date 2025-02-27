#include <Servo.h>
#include <Stepper.h>

// Librerías necesarias
#include <ShiftedLCD.h>
#include <SPI.h>

// Define los pines del joystick
const int pinX = A0; // Conexión analógica para el eje X
const int pinY = A1; // Conexión analógica para el eje Y

// Define los pines para el motor paso a paso y el servo
const int motorPin1 = 8;
const int motorPin2 = 9;
const int motorPin3 = 6;
const int motorPin4 = 12;

const int servoPin = 7; // Pin del Servo

// Número de pasos por revolución del motor
const int stepsPerRevolution = 2048;

// Rango de movimiento para el servo
const int servoMinAngle = 0;
const int servoMaxAngle = 180;

const int servoRestAngle = 90; // Angulo en el que el servo se detendrá al presionar el botón

// Delay de movientos del servo
const int servoMoveDelay = 15; // Ajusta este valor según sea necesario para cambiar la velocidad

bool buttonpressed = false;

int lastServoPosition = servoRestAngle; // Almacena la última posición del servo

const int SW_pin = 3;

const int Redled = 4;

// Crea objetos para el servo y el motor paso a paso
Servo myservo;
Stepper myStepper(stepsPerRevolution, motorPin1, motorPin3, motorPin2, motorPin4);
LiquidCrystal lcd(10);

void setup() {

  pinMode(SW_pin, INPUT_PULLUP);
  
  myservo.attach(servoPin);
  myservo.write(servoRestAngle); // Inicia el servo en 90 grados
  
  Serial.begin(9600);
  lcd.begin(16, 2);


}

void loop() {

  // Lee los valores de los ejes X y Y del joystick
  int xValue = analogRead(pinX);
  int yValue = analogRead(pinY);

  // Mapea los valores del joystick al rango de ángulos para el servo
  int servoAngle = map(xValue, 0, 1023, servoMinAngle, servoMaxAngle);
  
  // Mapea los valores del joystick a la velocidad para el motor paso a paso
  int stepperSpeed = map(yValue, 0, 1023, 0, 1000);

  int buttonState = digitalRead(SW_pin);

  if (buttonState == LOW && !buttonpressed){

    Serial.print(" -- Button is pressed! -- ");
    
    buttonpressed = true;
    
    lastServoPosition = myservo.read(); // Almacena la posición actual del servo
  
  } else if (buttonState == HIGH && buttonpressed) {
  
    Serial.println(" -- Button is not pressed. -- ");
  
    buttonpressed = false;
  
  }

  if (buttonpressed){
    
    myservo.write(lastServoPosition); // Mueve el servo a la última posición almacenada
    delay(servoMoveDelay); // Introduce un retraso para ralentizar el movimiento del servo
  
  } else {
  
    // Mueve el servo a la posición deseada con retraso
  
    for ( int angle = myservo.read(); angle != servoAngle; angle += ( servoAngle > myservo.read() ) ? 1 : -1 ) {

      myservo.write(angle);
      
      delay(servoMoveDelay);
  
    }
  
  }

  // Si el eje Y está en movimiento, mueve el motor paso a paso
  if (yValue > 900) {
  
    digitalWrite(Redled, HIGH);
  
    myStepper.setSpeed(12);
    myStepper.step(stepsPerRevolution);
  
    digitalWrite(Redled, LOW);

  } else if (yValue < 50) {

    digitalWrite(Redled, HIGH);
  
    myStepper.setSpeed(12);
    
    lcd.setCursor(0, 0);

    lcd.print("Moving Stepper");

    lcd.setCursor(2, 0);

    lcd.print("Down");

    myStepper.step(-stepsPerRevolution);
  
    digitalWrite(Redled, LOW);

    lcd.print(millis()/1000);


  }

  lcd.setCursor(0, 0);

  lcd.print("IG: J4ckris                        ");
  lcd.print("     LA GRUA                        ");


  // print the number of seconds since reset:

  lcd.print(millis()/1000);

  // Debug
  Serial.print("Servo : ");
  Serial.print(xValue);
  Serial.print(", Stepper: ");
  Serial.println(yValue);

  delay(50);
}
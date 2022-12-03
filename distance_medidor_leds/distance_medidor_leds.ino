/* Arduino Projects - by j4ckris ;)

Materials:

  - 4 led
  - 4 resistence
  - Ultasonic sensor
  - Jumpers
  - Potenciometer

*/
// Connect the following pins below

// Variables
int echo = 9;
int trig = 10;

float traveltime, distance;

int led_1 = 7;
int led_2 = 2;
int led_3 = 3;
int redled = 4;

void setup() {
  // put your setup code here, to run once:

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  pinMode(redled,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  traveltime = pulseIn(echo, HIGH);

  digitalWrite(trig, LOW);

  distance = (traveltime/2)/29.15; // Convert to CM from time 
  
  Serial.print("Distancia : ");
  Serial.print(distance);
  Serial.println();

  
  if (distance < 10) {

    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(redled, LOW);


  } else if( distance < 20) {

    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
    digitalWrite(redled, LOW);

  } else if (distance < 30){

    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(redled, LOW);

  } else if (distance < 40){

    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(redled, HIGH);

  } else if(distance > 30){

    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(redled, LOW);


  }else if (distance > 20){


    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, LOW);
    digitalWrite(redled, LOW);

  }else if (distance > 10){

    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(redled, LOW);
  

  }

}

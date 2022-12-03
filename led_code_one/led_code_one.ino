/*
Arduino Projects - by J4ckris

Materials:
  - 4 leds
  - 4 resistence
  - jumpers

*/


// Integer variables
int pin4 = 4;
int pin2 = 2;
int pin8 = 8;
int pin12 = 12;

float wait = 50.0; // Delay time, this is a float varible

int c = 0; // This will be a counter 
int round_ = 0 ; // Round Counter

String stopc = "[!] Now you can reset me please :}";

void setup() {
  
  pinMode(pin4, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin12, OUTPUT);

  Serial.begin(9600);
}

void loop() {
 
  digitalWrite(pin4, HIGH);
  delay(wait);
  digitalWrite(pin4, LOW);
  delay(wait);
  digitalWrite(pin2, HIGH);
  delay(wait);
  digitalWrite(pin2, LOW);
  delay(wait);
  digitalWrite(pin8, HIGH);
  delay(wait);
  digitalWrite(pin8, LOW);
  delay(wait);
  digitalWrite(pin12, HIGH);
  delay(wait);
  digitalWrite(pin12, LOW);
  delay(wait);

  c++; // adds one

  // Serial Monitor prints
  Serial.print("[*] Round : ");
  Serial.print(c);
  Serial.println(""); 

  if (c == 50){

    round_++;

    Serial.println("[+] Round " );
    Serial.print(round_);
    Serial.print(" Finished");

    delay(5000);
  }

// Program will say you in serial monitor to restart
  while (c > 200){

    Serial.println(stopc);

  }
}

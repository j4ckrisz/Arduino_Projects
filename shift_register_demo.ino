//shift register demo script

// Variables

int lachtPin = 8;
int clockPin = 13;
int dataPin = 4;

byte myByte = 0b1010101010;
byte myByte2 =0b0101010101;

void setup() {

  Serial.begin(9600);
  pinMode(lachtPin, OUTPUT);
  pinMode(clockPin, OUTPUT) ;
  pinMode(dataPin, OUTPUT);
}

void loop() {


  digitalWrite(lachtPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte);
  digitalWrite(lachtPin, HIGH);

  delay(2000);

  digitalWrite(lachtPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte2);
  digitalWrite(lachtPin, HIGH);



}

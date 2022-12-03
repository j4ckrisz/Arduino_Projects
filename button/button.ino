/* 

Arduino Projects - by J4ckris ;)

Materials:

 - 1 led
 - 1 button
 - 3 Jumpers
 - 1 resistence

 */

void setup() {
  // put your setup code here, to run once:

  pinMode(2, INPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int var1 = digitalRead(2);



  if (var1 == 1){

    digitalWrite(13, HIGH);

  }else{

    digitalWrite(13, LOW);



  }
  Serial.println(var1);

}

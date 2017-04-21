#include <Morse.h>
Morse morse(2);

String mensaje="0";
void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {

//Serial.println("Se envio mensaje");
digitalWrite(2,1);
delay(5000);
morse.Write("0");
digitalWrite(2,0);
delay(5000);
}

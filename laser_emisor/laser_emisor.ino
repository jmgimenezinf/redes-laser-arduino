#include <Morse.h>
Morse morse(2);

String mensaje="0";
void setup() {
   pinMode(2,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
morse.Write("s");
Serial.println("Se envio mensaje");

}

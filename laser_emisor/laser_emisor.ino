#include <Morse.h>
Morse morse(2);

String mensaje="0";
void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
signal_envio();
morse.Write("i");
signal_end_transmission();


}
void signal_envio(){
digitalWrite(2,1);
delay(3000);
digitalWrite(2,0);
}
void signal_end_transmission(){
digitalWrite(2,1);
delay(3000);
digitalWrite(2,0);
delay(3000);
}

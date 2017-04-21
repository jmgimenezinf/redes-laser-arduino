#include <Wire.h>
#include <BH1750.h>

int cont_low;
int cont_hight;
BH1750 lightMeter;
int pin_laser=4;
int tiempo_espera;
int time_max;

void setup() {
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println(F("LASER RECEPTOR"));
  time_max=2000;
}
void loop() {
  //  uint16_t lux = lightMeter.readLightLevel();

    Serial.println("Esperando senial emisora:");
    esperarEnvio();
    contarLuz();
    
}

void esperarEnvio(){
  int time_actual;
  time_actual=0;
  while (time_actual < time_max ){
      delay(1);
      if (lightMeter.readLightLevel()>0){
          time_actual=time_actual + 1;  
      }else{
          time_actual=0;    
      }
  }
  
  Serial.print("Supero el tiempo maximo de 1: ");
  Serial.println(time_actual);
  Serial.println("Comienza transmision");
}

void contarLuz(){
  while (true) {
    uint16_t lux = lightMeter.readLightLevel();
    cont_hight=0;
    cont_low=0;
   if (lux>0){
      cont_hight=cont_hight +1;
      delay(10);
      tiempo_espera=1;
      while (lightMeter.readLightLevel()>0){
          delay(tiempo_espera);
          cont_hight=cont_hight +1;
        }
          Serial.print("Cantidad de Unos:");
          Serial.println(cont_hight);
    }else {
        cont_low=cont_low + 1;
       // Serial.println(lux);
        delay(10);
        tiempo_espera=1;
        while (lightMeter.readLightLevel()== 0){
          delay(tiempo_espera);
          cont_low=cont_low +1;
        }
        Serial.print("Cantidad de Ceros:");
        Serial.println(cont_low);
      }
    }
}


#include <Wire.h>
#include <BH1750.h>

int cont_low;
int cont_hight;
BH1750 lightMeter;
int pin_laser=4;
int tiempo_espera;
const int time_max=2000;
int msj_recibido[256];
void setup() {
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println(F("LASER RECEPTOR"));
}
void loop() {
  //  uint16_t lux = lightMeter.readLightLevel();

    Serial.println("Esperando senial emisora:");
    esperarEnvio();
    recibirDatos();
    
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


void recibirDatos(){
  int i = 0;
  int cont_hight =0;
  int cont_low = 0;
  
  while (cont_hight<time_max) {
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
          i++;
          if (i<254){
                msj_recibido[i]=cont_hight;
                Serial.print("vector ");
                Serial.print(i);
                Serial.print(" ");
                Serial.println(msj_recibido[i]);
          } 
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
        i++;
        if (i<254){
          msj_recibido[i]=cont_low;  
          Serial.print("vector ");
          Serial.print(i);
          Serial.print(" ");
          Serial.println(msj_recibido[i]);
        } 
      }
    }
}


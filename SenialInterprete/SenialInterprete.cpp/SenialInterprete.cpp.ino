#include <Wire.h>
#include <BH1750.h>

int cont_low;
int cont_hight;
BH1750 lightMeter;
int pin_laser=2;

void setup() {
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println(F("LASER RECEPTOR"));
  attachInterrupt(digitalPinToInterrupt(pin_laser),contarLuz,CHANGE);
}
void loop() {
    uint16_t lux = lightMeter.readLightLevel();
    cont_hight=0;
    cont_low=0;
    Serial.println("Esperando señal emisora:");
}

void contarLuz()
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


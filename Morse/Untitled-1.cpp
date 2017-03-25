
#define ENCENDER_BH1750 0x01
#define RESETEAR_BH1750 0x07
#define DIRECCION_BH1750_0 0x23
#define DIRECCION_BH1750_1 0x5C
#define MEDIDA_CONTINUA_CUATRO_LUX_BH1750 0x13
#include <Wire.h>
#include <BH1750.h>
int tiempo_espera;
int cont_low;
int cont_hight;
BH1750 lightMeter;
void setup() {
  Serial.begin(9600);
  lightMeter.begin();
  Serial.println(F("BH1750 Test"));
}
void loop() {
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

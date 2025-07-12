#include <RCSwitch.h>

RCSwitch emisor = RCSwitch();
static char binarioBuf[33];
void setup() {

 Serial.begin(9600);

 //Establecemos el pin D10 como el pin de data al transmisor
 emisor.enableTransmit(10);

 //Configuramos la longitud del pulso
 emisor.setPulseLength(351);

 //Establecemos el protocolo como 1
 emisor.setProtocol(1);
}

void loop() {

 emisor.send("111100100001111110110110"); //Maxima velocidad
 delay(15000); //duerme durante 15 segundos, espera a que el ventilador alcanze velocidad

 emisor.send("111100100001111110111100"); //Apagar el ventilador
 delay(15000);//duerme durante 15 segundos, espera a que el ventilador pierda velocidad

 emisor.send("111100100001111110110101"); //Apagar/Encender la luz.
 delay(15000);//duerme durante 15 segundos, espera 15 segundos

}
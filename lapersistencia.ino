//Programa SD_HOLA (adaptado Prof: BOLAÑOS 2018
//Incluir las líbrerias necesarias
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>
#define pinSD 10 //define el pin para seleccionar la tarjeta SD
TMRpcm tmrpcm; //Se crea un objeto de la librería TMRpcm
  int led = 2;
  int boton = 3;
  int boton2 = 4;
  int boton3 = 5;
  // Declaracion de variables globales
  
// Pin analogico de entrada para el LDR chico
  int pinLM35 = 1; // Variable del pin de entrada del sensor (A2)

 
// Pin analogico de entrada para el LDR GRANDE
int pinLDR = 2; //(A1)??
 
// Variable donde se almacena el valor del LDR -GRANDE
int valorLDR = 0;  
// Variable donde se almacena el valor del LDR - CHICO
int tempC=0;
   
void setup(){
  
  pinMode(led,OUTPUT);
  pinMode(boton,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  digitalWrite(led,LOW);
  tmrpcm.speakerPin = 9; //Se define el pin en el que está conectada la bocina
  Serial.begin(9600); //Se inicia la comunicación serial
  
  if (!SD.begin(pinSD)) { // see if the card is present and can be initialized:
    Serial.println("Fallo en la tarjeta SD"); //Aviso de que algo no anda bien
    return; //No hacer nada si no se pudo leer la tarjeta
  }
}


void loop(){
  boton = digitalRead(3);
  boton2 = digitalRead(4);
  boton3 = digitalRead(5);

 
  if (boton==LOW){
      Serial.println("Reproduciendo Boton"); 
      Serial.println("BEBE sofi");
     Serial.println("blec WAV"); 
      tmrpcm.play("sofi.wav");
      digitalWrite(led,HIGH);
      delay(30000); //Espera medio minuto para volver a reproducirlo
      digitalWrite(led,LOW);
      tmrpcm.disable();
     return;
  }

  

  
 /*  NO USARRRRRRRRRR NO ANDAAAAAAAAAAAAA!!!!!!!
  *  if (boton2==LOW){
      Serial.println("Reproduciendo Boton 2"); 
      Serial.println("GRANDE 2 - mix");
      Serial.println("mix WAV-");
       tmrpcm.play("blemix.wav");
      //tmrpcm.play("mix.wav");
      digitalWrite(led,HIGH);
      delay(30000); //Espera medio minuto para volver a reproducirlo
      digitalWrite(led,LOW);
    tmrpcm.disable();
      return;
  }
  */

  
  if (boton3==LOW){
      Serial.println("Reproduciendo Boton 3"); 
      Serial.println("dani WAV mediano-"); 
    
       tmrpcm.play("dani.wav");
    
      digitalWrite(led,HIGH);
      delay(30000); //Espera medio minuto para volver a reproducirlo
      digitalWrite(led,LOW);
      tmrpcm.disable();
      return;
  }


  // Guardamos el valor leido del ADC en una variable
  // El valor leido por el ADC (voltaje) aumenta de manera directamente proporcional
  // con respecto a la luz percibida por el LDR
  valorLDR= analogRead(pinLDR);
  
  // Devolver el valor leido a nuestro monitor serial en el IDE de Arduino

   Serial.println("SENSOR GRANDE: "); 
  Serial.println(valorLDR);
 
  // Encender los leds apropiados de acuerdo al valor de ADC

  if(valorLDR >=990)  // LDR GRANDE
  {
     Serial.println("Reproduciendo DE LDR");
     Serial.println("CIN - ENSAYO SOBREVIVENCIA - LDR GRANDE");  
      tmrpcm.play("blec.wav");
      digitalWrite(led,HIGH);
      delay(30000); //Espera medio minuto para volver a reproducirlo
      digitalWrite(led,LOW);
      tmrpcm.disable();
      return;
  }

  


   // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
   tempC = analogRead(pinLM35);
     Serial.println("SENSOR LDR CHICO: "); 
     Serial.println(tempC);
     
   if(tempC>=29){    //LDR CHICO
     Serial.println("Reproduciendo DE SENSOR TEMP"); 
     Serial.println("BLEMIX - LDR CHICO"); 
      tmrpcm.play("blemix.wav");
      digitalWrite(led,HIGH);
      delay(30000); //Espera medio minuto para volver a reproducirlo
      digitalWrite(led,LOW);
      tmrpcm.disable();
      return;

 
      
    }
  
  
}

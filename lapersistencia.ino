//Programa LAPERSISTENCIA
//Incluir las líbrerias necesarias - lectura SD y TMRpcm- SPI para puertos seriales
#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>
#define pinSD 10 //define el pin para seleccionar la tarjeta SD
//Se crea un objeto de la librería TMRpcm
 
 TMRpcm tmrpcm;

  int led = 2;
  int infrarrojo1 = 3;
  int infrarrojo2 = 4;
  int infrarrojo3 = 5;
  // Declaracion de variables globales
  
// Pin analogico de entrada para el LDR chico
  int pinLDRchico = 1; // Variable del pin de entrada del sensor (A2)

 
// Pin analogico de entrada para el LDR GRANDE
int pinLDR = 2; 
 
// Variable donde se almacena el valor del LDR -GRANDE
int valorLDR = 0;  

// Variable donde se almacena el valor del LDR - CHICO
int tempC=0;
   
void setup(){
  
  pinMode(led,OUTPUT);
  pinMode(infrarrojo1,INPUT);
  pinMode(infrarrojo2,INPUT);
  pinMode(infrarrojo3,INPUT);
  digitalWrite(led,LOW);

  tmrpcm.speakerPin = 9; //Se define el pin en el que está conectado el parlante
  Serial.begin(9600); //Se inicia la comunicación serial
  
  if (!SD.begin(pinSD)) { // corrobora si la tarjeta que utilizamos puede ser inicializada
    Serial.println("Fallo en la tarjeta SD"); 
    return; //No hacer nada si no se pudo leer la tarjeta
  }
}


void loop(){

  infrarrojo1 = digitalRead(3);
  infrarrojo2 = digitalRead(4);
  boton3 = digitalRead(5);

 
   if (infrarrojo1==LOW){
      Serial.println("Reproduciendo infrarrojo 1"); 
      tmrpcm.play("sofi.wav");
      digitalWrite(led,HIGH);
      delay(30000); //Espera medio minuto para volver a reproducirlo
      digitalWrite(led,LOW);
      tmrpcm.disable();
      return;
  }

  
  if (infrarrojo2==LOW){
      Serial.println("Reproduciendo infrarrojo 2");
       tmrpcm.play("blemix.wav");
      digitalWrite(led,HIGH);
      delay(30000); //Espera medio minuto para volver a reproducirlo
      digitalWrite(led,LOW);
     tmrpcm.disable();
      return;
  }
  
 
  if (infrarrojo3==LOW){
      Serial.println("Reproduciendo infrarrojo 3"); 
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
 
 
  if(valorLDR >=990)  // LDR GRANDE
  {
      Serial.println("Reproduciendo DE LDR GRANDE");
      tmrpcm.play("blec.wav");
      digitalWrite(led,HIGH);
      delay(30000); //Espera medio minuto para volver a reproducirlo
      digitalWrite(led,LOW);
      tmrpcm.disable();
      return;
  }

  

  // Guardamos el valor leido del ADC en una variable
  // El valor leido por el ADC (voltaje) aumenta de manera directamente proporcional
  // con respecto a la luz percibida por el LDR

   tempC = analogRead(pinLDRchico);
   Serial.println("SENSOR LDR CHICO: "); 
   Serial.println(tempC);
     
   if(tempC>=29){    //LDR CHICO
     Serial.println("Reproduciendo - LDR CHICO"); 
      tmrpcm.play("blemix.wav");
      digitalWrite(led,HIGH);
      delay(30000); //Espera medio minuto para volver a reproducirlo
      digitalWrite(led,LOW);
      tmrpcm.disable();
      return;
    
    }
  
  
}

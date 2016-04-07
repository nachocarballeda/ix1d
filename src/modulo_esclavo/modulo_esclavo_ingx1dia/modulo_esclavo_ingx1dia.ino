#include "ultrasonic_sensors.h"

#define BOMBA_A 1
#define BOMBA_B 2
UltrasonicSensors usSensors;


const int ledVerde1 = 5;
const int ledAmarillo1 = 6;
const int ledRojo1 = 7;
const int RELAY1 = 8;
const int RELAY2 = 9;
long sensor_a;
long sensor_b;
char dato_entrante;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  
  Serial1.begin(38400); //for  TTL in arduino Leonardo use Serial1. se tiene que usar esta velocidad SI o SI
  
  pinMode(13, OUTPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledRojo1, OUTPUT);
  pinMode(ledAmarillo1, OUTPUT);
  apagar(BOMBA_A);
  apagar(BOMBA_B);
}


// the loop function runs over and over again forever
void loop(){
  
    leerSensores(); 
    char dato_entrante = Serial1.read();
    if(dato_entrante == 'A'){
      encender(BOMBA_A);
    } 
    else if(dato_entrante == 'B'){
      encender(BOMBA_B);
    }
    
    else if(dato_entrante == 'C'){
      apagar(BOMBA_A);
    }
    
    else if(dato_entrante == 'D'){
      apagar(BOMBA_B);
    }
    
    else if(dato_entrante == 'M'){
      Serial1.println(sensor_a);
    }
    
    else if(dato_entrante == 'N'){   
      Serial1.println(sensor_b);
    }
    
    else if(dato_entrante == 'R'){   
      prenderLedsTanque1(3);
    }
    
    else if(dato_entrante == 'E'){   
      prenderLedsTanque1(2);
    }
    
    else if(dato_entrante == 'W'){   
      prenderLedsTanque1(1);
    }
    
    else if(dato_entrante == 'Q'){   
      prenderLedsTanque1(0);
    }
  delay(200);   
}


void encender(int bomba){
  if (bomba == 1)
    digitalWrite(RELAY1, LOW);
  else if (bomba == 2)
    digitalWrite(RELAY2, LOW);
  else
    return;
}

void apagar(int bomba){
  if (bomba == 1)
    digitalWrite(RELAY1, HIGH);
  else if (bomba == 2)
    digitalWrite(RELAY2, HIGH);
  else
    return;
}

void escribirSerial(byte outByte){
  if (Serial1.available()) {
//  int inByte = Serial.read();
  Serial1.write(outByte);
  }
}

void escribirZigbee(char outChar){
  if (Serial1.available()) {
    Serial1.write(outChar);
  }
}

void leerSensores(void){
  sensor_a = usSensors.a();
  delay(1);
  sensor_b = usSensors.b();
  delay(1);
}

void prenderLedsTanque1(int cantidad){
  if (cantidad < 0 || cantidad > 3)
    return;
  switch (cantidad){
    case 0:
      digitalWrite(ledVerde1,HIGH);
      digitalWrite(ledAmarillo1,HIGH);
      digitalWrite(ledRojo1,HIGH);
      break;
    case 1:
      digitalWrite(ledVerde1,LOW);
      digitalWrite(ledAmarillo1,HIGH);
      digitalWrite(ledRojo1,HIGH);
      break;
    case 2:
      digitalWrite(ledVerde1,LOW);
      digitalWrite(ledAmarillo1,LOW);
      digitalWrite(ledRojo1,HIGH);
      break;
    case 3:
      digitalWrite(ledVerde1,LOW);
      digitalWrite(ledAmarillo1,LOW);
      digitalWrite(ledRojo1,LOW);
      break;
    default:
      break;
  }
}


void sonarAlarma (){
  return;

}

/*The Arduino Leonardo 
 * board uses Serial1 to 
 * communicate via TTL (5V) 
 * serial on pins 0 (RX) and 1 (TX). 
 * Serial is reserved for USB CDC communication. 
 */


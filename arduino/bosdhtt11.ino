#include "DHT.h"
#define dhtPin 12
#define dhtType DHT11

DHT dht(dhtPin,dhtType);
int humidityVal;
char data;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
 pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
   pinMode(4, OUTPUT);
 analogWrite(6, LOW);
 analogWrite(5, LOW); 
}

void loop() {
  data = Serial.read();
    if(data =='0')
{ 
digitalWrite(4,HIGH);
delay(2000);
digitalWrite(4,LOW);
   Serial.write('0');
  }
humidityVal = dht.readHumidity();

Serial.print(humidityVal);
delay(2000);
if ( humidityVal <60)
  {
    analogWrite(6, 255);
    analogWrite(5, LOW);
   digitalWrite(4,LOW);  
  }
 else 
  {
    analogWrite(6, LOW);
    analogWrite(5, 255);
      digitalWrite(4,HIGH); 
      delay(2000);
      digitalWrite(4,LOW); 
   
  }
}

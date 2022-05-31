#include "DHT.h"

#define DHTPIN 2 //digital pin connected to the DHT sensor

#define DHTTYPE DHT11 //DHT 11
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT final");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if(isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Failed to read from DHt sensor:"));
    return;
  
  }


  float hif = dht.computeHeatIndex(f,h);
  float hic = dht.computeHeatIndex(t,h,false);

  Serial.println(t);
  Serial.println(h);
   }

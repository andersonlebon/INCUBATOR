
#include "DHT.h"
#define DHTPIN 7    
  // Uncomment whatever type you're using!
  #define DHTTYPE DHT11 
  DHT dht(DHTPIN, DHTTYPE); 
  int relay1 = 2;
  int relay2 = 3;
  int relay3 = 4;
  int relay4 = 5;

void setup() {
    Serial.begin(9600);
    dht.begin();    
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, 1);
    digitalWrite(relay3, 1);
    digitalWrite(relay4, 1);

}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);


  // Check if any reads failed and exit early (to try again).
  if (isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, false);

  if(hic <= 19){
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
    Serial.println(hic);
    Serial.println("low T");
  }
    if(hic >19  && hic <22 ){
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
    Serial.println(hic);
    Serial.println("Medium T");
   
  }
    if(hic >= 23){
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
    Serial.println(hic);
    Serial.println("High T");
  }
  else {
    Serial.println(hic);}

}

#include "DHT.h"

#define DHTTYPE DHT22

//for Arduino UNO
//#define DHTPIN 7

//for NodeMCU
#define DHTPIN D2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT22 Test...!!"));
  dht.begin();
}

void loop() {
  delay(5000);
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temp)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  showValue(humidity, temp);
}

void showValue(float humidVal, float tempVal) {
  // Compute heat index in Celsius (isFahreheit = false)
  float heatCelsius = dht.computeHeatIndex(tempVal, humidVal, false);
  Serial.println("Humidity: " + String(humidVal, 1) + " % | " + "Temperature: " + String(tempVal, 1) + " °C | " + "Heat index: " + String(heatCelsius, 1) + " °C");
}

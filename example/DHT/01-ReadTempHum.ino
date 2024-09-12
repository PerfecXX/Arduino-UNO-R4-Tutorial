#include <DHT.h>

#define DHTPIN 8      
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);   
  dht.begin();           
}

void loop() {
  delay(2000);           

  float humidity = dht.readHumidity();    
  float temperature = dht.readTemperature(); 


  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
}

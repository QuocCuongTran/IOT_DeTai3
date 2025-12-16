#include <DHT.h>

#define DHTPIN 7          // DHT22 data pin
#define DHTTYPE DHT22
#define FAN_LED 3         // LED = fan
#define ON_TEMP 30        // °C threshold

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(FAN_LED, OUTPUT);
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  float t = dht.readTemperature();   // read °C
  Serial.print("Temp: "); Serial.print(t); Serial.println(" C");

  if (t > ON_TEMP) {
    digitalWrite(FAN_LED, HIGH);     // fan ON
  } else {
    digitalWrite(FAN_LED, LOW);      // fan OFF
  }
  delay(2000);                       // update every 2 s
}

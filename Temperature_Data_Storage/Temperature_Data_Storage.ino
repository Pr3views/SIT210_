// This #include statement was automatically added by the Particle IDE.

#include <Adafruit_DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22



DHT dht(DHTPIN, DHTTYPE);
int led = D7;






void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
    dht.begin();
}

void loop() {
    float temp = dht.getTempCelcius();
    digitalWrite(led, LOW);
    delay(5000);
    if(!isnan(temp))
    {
        Particle.publish("temp", String::format("%.1f", temp), PRIVATE);
        digitalWrite(led, HIGH);
        Serial.print("Temp: ");
        Serial.println(temp);
    }

}

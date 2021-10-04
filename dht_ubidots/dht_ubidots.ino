#include <DHT.h>
#include <UbidotsMicroESP8266.h>

#define DHTPIN 4
#define DHTTYPE DHT11

char auth[] = "BBFF-0kFPjZRJqbINSZ3Z6F8MV4cWgIIlyB"; // token yang dikirim dari blynk ke email masing2
char ssid[] = "realme3";
char pass[] = "12345678";

DHT dht(DHTPIN, DHTTYPE);
Ubidots client(auth);
unsigned long last = 0;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    dht.begin(); //sensor mulai membaca suhu dan kelembapan
    delay(20); // delay 0.02 detik
    client.wifiConnection(ssid, pass); //menyambungkan ubidots client dengan wifi
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-last>10000{ //jika sudah 10 detik
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  last = millis();
  client.add("kelembapan",hum); //ubidots client membaca kelembapan
  client.add("Temperatur",temp); //ubidots client membaca suhu
  client.sendAll(true); //ubidots client mengirimkan semua data
  
  
  }
}

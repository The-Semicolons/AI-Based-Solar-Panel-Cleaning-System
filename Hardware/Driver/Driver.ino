#include <Servo.h>
#include <EduIntro.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

int ldr00 = A0;
int ldr10 = A1;
int ldr01 = A2;
int ldr11 = A3;
int led = 13;
int servotoppin1 = 12;
int servotoppin2 = 11;
int servobasepin = 10;
int dhtpin = 9;
int solaroutpin = A7;

Servo servotop1, servotop2, servobase;

DHT11 dht(dhtpin);

Adafruit_BME280 bme;

int ldr00val, ldr10val, ldr01val, ldr11val;

int ghi = 112;
int temperature = 22;
int humidity = 12;
int pressure = 1;
int altitude = 1251;

void setup() {
  Serial.begin(9600);
  // servotop1.attach(servotoppin1);
  // servotop2.attach(servotoppin2);
  // servobase.attach(servobasepin);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  bme.begin();
}

void loop() {
  int ldr00val = analogRead(ldr00);
  int ldr10val = analogRead(ldr10);
  int ldr01val = analogRead(ldr01);
  int ldr11val = analogRead(ldr11);
  int solaroutput = analogRead(solaroutpin)/10;
  int Ghi = (ldr00val+ldr10val+ldr01val+ldr11val)/4;
  int Temperature = dht.readCelsius();
  int Humidity = dht.readHumidity();
  int Pressure = bme.readPressure() / 100.0F;
  int Altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  Serial.print("[");
  Serial.print(ghi);
  Serial.print(", ");
  Serial.print(temperature);
  Serial.print(", ");
  Serial.print(humidity);
  Serial.print(", ");
  Serial.print(pressure);
  Serial.print(", ");
  Serial.print(altitude);
  Serial.print(", ");
  Serial.print(solaroutput);
  Serial.println("]");
  delay(5000);
}
 
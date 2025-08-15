 #include <Adafruit_SSD1306.h>
#include "DHT.h"
#define DHTPIN 4 
#define DHTTYPE DHT11
DHT Dht (DHTPIN,DHTTYPE);
float temp, hum;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display (SCREEN_WIDTH, SCREEN_HEIGHT, &Wire,-1);



void setup() {
  // put your setup code here, to run once:
  Dht.begin();
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC,0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  temp=Dht.readTemperature();
  hum=Dht.readHumidity();

}

void loop() {
  // put your main code here, to run repeatedly:
  display.print("TEMPERATURE: ");
  display.println(temp);
  display.print("HUMIDITY:");
  display.println(hum);
  delay(2000);
  display.display();

}

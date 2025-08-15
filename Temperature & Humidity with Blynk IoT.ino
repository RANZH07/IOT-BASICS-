#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3IICYb9g7"
#define BLYNK_TEMPLATE_NAME "TEMPERATURE HUMIDITY MONITOR"
#define BLYNK_AUTH_TOKEN "vWCK09bnOiO3qTDh3iq5BClqvxvQFZ-Q"



#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include<WifiClient.h>
#include "DHT.h";

char auth[]= BLYNK_AUTH_TOKEN;
char ssid[]="realme 9 5G Speed Edition";
char pass[]="ammu1234";
BlynkTimer timer;

#define BUZZER 13


#define DHTPIN 4
#define DHTTYPE DHT11

DHT Dht(DHTPIN,DHTTYPE);
float temp=0;
float hum=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //Standard bard rates are 9600 and 115200
  pinMode(BUZZER, OUTPUT);
  Dht.begin(); 
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(10006L,sendSensor);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}
void sendSensor(){ //copy and paste whatever is there in the loop of dht11_example pgm in the sendSensor loop of this pgm, applies to any example
  temp=Dht.readTemperature();
  hum=Dht.readHumidity();
  Serial.print("Temperature : ");
  Serial.println(temp);
  Serial.print("Humidity : ");
  Serial.println(hum);
  delay(1000);
  Blynk.virtualWrite(V0,temp);
  Blynk.virtualWrite(V1,hum);

}
BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Blynk.virtualWrite(V2,value);
  if(value==1){
    digitalWrite(BUZZER, HIGH);
  }
  else{
    digitalWrite(BUZZER, LOW);
  }
}

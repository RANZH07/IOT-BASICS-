#include<stdio.h>

#define DHTPIN 4
uint8_t RHI, RHD, TCI, TCD, SUM;
uint8_t Presence = 0;
float tCelsius = 0;
float tFahrenheit = 0;
float RH = 0;





void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
   delay(2000);
  DHT11_Start();
  Response_signal();
  
	RHI = DHT11_Read(); // Relative humidity integral
	RHD = DHT11_Read(); // Relative humidity decimal
	TCI = DHT11_Read(); // Celsius integral
	TCD = DHT11_Read(); // Celsius decimal
	SUM = DHT11_Read(); // Check sum
  
	if (RHI + RHD + TCI + TCD == SUM)
	  {
	  // Can use RHI and TCI for any purposes if whole number only needed
	    tCelsius = (float)TCI + (float)(TCD/10.0);
	    tFahrenheit = tCelsius * 9/5 + 32;
	    RH = (float)RHI + (float)(RHD/10.0);
	  // Can use tCelsius, tFahrenheit and RH for any purposes
	  }
	        //Serial.print()
    printf("TEMPERATURE : %f\n",tCelsius);
	  printf("HUMIDITY : %f\n",RH);


	  
  }
void DHT11_Start()
{
  Serial.println("DHT11_Start");
  pinMode(DHTPIN,OUTPUT);
  digitalWrite(DHTPIN,LOW);
  delay(18);
  digitalWrite(DHTPIN,HIGH);
  delayMicroseconds(30);
  pinMode(DHTPIN,INPUT);
  
}

uint8_t Response_signal (void)
{
	uint8_t Response = 0;
	delayMicroseconds(40);
  int a = digitalRead(DHTPIN);
 	if (!(digitalRead(DHTPIN)))
	{
		delayMicroseconds (80);
		if ((digitalRead(DHTPIN)))
    { 
      Response = 1;
    }
		else
    { 
      Response = -1;
    }
	}
	while ((digitalRead(DHTPIN)));   // wait for the pin to go low
   
	return Response;
}

uint8_t DHT11_Read (void)
{
  uint8_t a,b =0;
  for (a=0;a<8;a++)
  {
    while (!(digitalRead(DHTPIN)));
    delayMicroseconds(40);   // wait for 40 us
    if (!(digitalRead(DHTPIN)))   // if the pin is low
      b&= ~(1<<(7-a));
    else
      b|= (1<<(7-a));
    while ((digitalRead(DHTPIN)));
      }
  return b;
}

}

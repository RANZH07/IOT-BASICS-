#define TRIGER 2
#define ECHO 19
#define BUZZER 34
long duration;
float distance =0;

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIGER,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(BUZZER,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIGER,LOW);
  delayMicroseconds(500);
  digitalWrite(TRIGER,HIGH);
  delayMicroseconds(500);
  distance=0.0343 * (duration /2);//340metre/sec
  Serial.print("Distance measured(CM): ");
  Serial.println(distance);
  delay(1000);
  if ( distance<20){
    digitalWrite(BUZZER,HIGH);
    delay(100);
    digitalWrite(BUZZER,LOW);
    delay(100);
  }
  else if(distance>20 && distance<60){
    digitalWrite(BUZZER,HIGH);
    delay(1000);
    digitalWrite(BUZZER,LOW);
    delay(1000);
  }
  else if(distance >60 && distance < 100){
    digitalWrite(BUZZER,HIGH);
    delay(3000);
    digitalWrite(BUZZER,LOW);
    delay(3000);
  }
  else {
    digitalWrite(BUZZER,LOW);
  }

  




}

#define  TRIG 12
#define  ECHO 13
long duration;
float distance1=0;
float distance2=0;
void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  
  distance1 = 13385.8*(duration/2);
  distance2=0.0343*(duration/2);
  Serial.print("DISTANCE MEASURED in inches:");
  Serial.println("DISTANCE MEASURED IN CM:");
  Serial.println(distance1);
  Serial.println(distance2);
  delay(1000);
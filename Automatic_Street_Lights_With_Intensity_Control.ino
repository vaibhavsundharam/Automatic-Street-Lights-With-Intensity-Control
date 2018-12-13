#define trigPin1 13
#define echoPin1 12
#define trigPin2 8
#define echoPin2 7
#define trigPin3 4
#define echoPin3 2  
#define LDRpin A0
int ledpin1 = 11;
int ledpin2 = 10;
int ledpin3 = 6;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin2,INPUT);
  pinMode(trigPin3,OUTPUT);
  pinMode(echoPin3,INPUT);
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(ledpin3,OUTPUT);
}
void loop() 
{
//FIRST ULTRASOUND  
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = ((duration1)/2) / 29.1;

  //SECOND ULTRASOUND
  long duration2, distance2;
  digitalWrite(trigPin2, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = ((duration2)/2) / 29.1;

  //THIRD ULTRASOUND
  long duration3, distance3;
  digitalWrite(trigPin3, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = ((duration3)/2) / 29.1;

  // MAIN SEQUENCE START

  //SEQUENCE 1
  if((distance1)>=5 && (distance1)<=15)
  {
    Serial.print(distance1);
    Serial.println(" cm");
    int val1;
  val1=analogRead(LDRpin);
  val1=constrain (val1,190,760);
   int ledlevel1=map(val1,190,760,255,0);
   analogWrite ((ledpin1),ledlevel1);
   delay(100);  
  }
   else if((distance2)>=5 && (distance2)<=15)
  {
    analogWrite((ledpin1),0);
  }  

//SEQUENCE 2
if((distance2)>=5 && (distance2)<=15)
  {
    Serial.print(distance2);
    Serial.println(" cm");
    int val2;
  val2=analogRead(LDRpin);
  val2=constrain (val2,190,760);
   int ledlevel2=map(val2,190,760,255,0);
   analogWrite ((ledpin2),ledlevel2);
  delay(100);
  }
else if((distance3)>=5 && (distance3)<=15)
  {
    analogWrite((ledpin2),0);
  }

//SEQUENCE 3
  if((distance3)>=5 && (distance3)<=15)
  {
    Serial.print(distance3);
    Serial.println(" cm");
    int val3;
  val3=analogRead(LDRpin);
  val3=constrain (val3,190,760);
   int ledlevel3=map(val3,190,760,255,0);
   analogWrite ((ledpin3),ledlevel3);
   delay(100);
  }
  else
  {
    analogWrite((ledpin3),0);
  }
  }


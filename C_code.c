#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

#define servoPin1 2
#define servoPin2 3
#define servoPin3 4
#define servoPin4 5
#define servoPin5 6
#define servoPin6 10
//HC-SR04 Distance sensor 
#define trigPin 50
#define ecoPin 52

//Conveyor Belt 
#define conveyor_forward 40
#define conveyor_back 38
#define speed 10

//Color Sensor
#define s0 28
#define s1 30
#define s2 32
#define s3 34
#define out 36
int red, green, blue;
String color;

long distance,duration;
void setup()
{
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
  servo6.attach(servoPin6);

  pinMode(s0, OUTPUT); //s0
  pinMode(s1, OUTPUT); //s1
  pinMode(s2, OUTPUT); //s2
  pinMode(s3, OUTPUT); //s3
  pinMode(out, INPUT); //out
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);


  pinMode(conveyor_forward,OUTPUT); //out
  pinMode(conveyor_back,OUTPUT); //out
  pinMode(hiz,OUTPUT); //out
 
  pinMode(trigPin, OUTPUT);
  pinMode(ecoPin, INPUT);
  
   Serial.begin(9600);
}
void loop()
{
   analogWrite(hiz,160);//band speed is adjusted
//Calibrate();
  Calibrated();
  digitalWrite(conveyor_forward,HIGH);
  digitalWrite(conveyor_back,LOW);
MeasuringDistance();   

   if (distance <4)
  {
  SetColor();
    if (renk == "red")
    {
    analogWrite(hiz,0);
    Serial.println("red1111");
      
      Servo1_close();
      delay(50);
      Servo2_back(90);
      delay(50);   
      Servo3_left();
      delay(50); 
      Servo1_open();
      delay(50);         
      Servo3_right();
      delay(50);        
      Servo2_forward(90);
      delay(50);
   
    }
  else  if (color == "green")
    {
   analogWrite(speed,0);
   Serial.println("green");
      
      
      Servo1_close();
      delay(50);
      Servo2_back(60);
      delay(50);   
      Servo3_left();
      delay(50); 
      Servo1_open();
      delay(50);         
      Servo3_right();
      delay(50); 
      Servo2_forward(60);
      delay(50);
   
   
    }
    else if (color == "blue")
    {
      analogWrite(speed,0);
      Serial.println("blue");
      
      
      Servo1_close();
      delay(50);
      Servo2_back(30);
      delay(50);   
      Servo3_left();
      delay(50); 
      Servo1_open();
      delay(50);         
      Servo3_right();
      delay(50);        
      Servo2_forward(30);
      delay(50);   
   
    }
delay(200);
  }
}

void SetColor()
{
  if (red < 60)
  {
    color="red";
  }
  else if (green < 60)
  {
     color="green";
   }
  else if (blue < 60)
  {
     color="blue";
  }
  delay(100);
}

void MeasuringDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(ecoPin, HIGH);
  distance = duration * 0, 034 / 2;
  Serial.println("distance : " + distance);
}
void Servo1_open()
{
  for (int i = 0; i < 90; i++)
  {
    servo1.write(i);
    delay(50);
  }
}
void Servo1_close()
{
  for (int i = 90; i > 0; i--)
  {
    servo1.write(i);
    delay(50);
  }
}
void Servo2_back(int value)
{
  for (int i = deger; i >0; i--)
  {
   servo2.write(i);
    delay(50);
  }
}
void Servo2_forward(int value)
{
  for (int i = 0; i <value; i++)
  {
   servo2.write(i);
    delay(50);
  }
}
void Servo3_right()
{
  for (int i = 0; i <90; i++)
  {
   servo3.write(i);
    delay(50);
  }
}
void Servo3_left()
{
  for (int i = 90; i >0; i--)
  {
   servo3.write(i);
    delay(50);
  }
}
void Calibrated()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = pulseIn(out, LOW);
  red = map(red, 50, 230, 0, 100);
  delay(100);

  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  green = pulseIn(out, LOW);
  green = map(green, 42, 210, 0, 100);
  delay(100);

  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  blue = pulseIn(out, LOW);
  blue = map(blue, 60, 220, 0, 100);
  delay(100);
  Serial.println();
}


void Calibrated()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = pulseIn(out, LOW);
  Serial.print("red");
  Serial.print(red);
  Serial.print("      ");
  delay(100);

  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  green = pulseIn(out, LOW);
  Serial.print("green");
  Serial.print(green);
  Serial.print("      ");
  delay(100);

  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  blue = pulseIn(out, LOW);
  Serial.print("blue");
  Serial.print(blue);
  Serial.print("      ");
  delay(100);
  Serial.println();
}
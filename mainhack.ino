#include<Servo.h> // servo motor  
#include<test_wifi.c>
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define buzzer 4
#define led1 6

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(buzzer, OUTPUT); // set the echo pin as an input
  pinMode(led1, OUTPUT); // set input pin as 6
  Serial.begin(19200); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5000);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5000);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  if (distance < 10)
  {
    digitalWrite(buzzer, HIGH);   //Setting the pin 4
    tone(buzzer, 95); //Frequency higher when detection is nearer
    digitalWrite(led1,HIGH);
    Serial.print("Distance: \n"); // print distance
    Serial.print(distance);
    Serial.println(" cm");
  }
    else if (distance < 15 && distance > 10)
  {
    digitalWrite(buzzer, HIGH);   //Setting the pin 4
    tone(buzzer, 15); //Frequency lower when detection is further
    digitalWrite(led1,HIGH);
    Serial.print("Distance: \n"); // print distance
    Serial.print(distance);
    Serial.println(" cm");
  }
  else 
  {
    digitalWrite(buzzer, LOW);   //Setting the pin 4
    noTone(buzzer); // No alarm when detection is clear
    digitalWrite(led1,LOW);
    Serial.print("Distance: \n"); // print distance
    Serial.print(distance);
    Serial.println(" cm");
  }

}

#include <Servo.h>
Servo servo;
int TRIG_PIN = 13;
int ECHO_PIN = 12;
int MOTOR_PIN1 = 6;
int MOTOR_PIN2 = 5;
int MOTOR_PIN3 = 10;
int MOTOR_PIN4 = 11;
float SPEED_OF_SOUND = 0.0345;
unsigned long Buffer_Time;

void setup() {
  pinMode (MOTOR_PIN1, OUTPUT);
  pinMode (MOTOR_PIN2, OUTPUT);
  pinMode (MOTOR_PIN3, OUTPUT);
  pinMode (MOTOR_PIN4, OUTPUT);
  pinMode (TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode (ECHO_PIN, INPUT);
  Serial.begin (9600);
  servo.attach(3);
  servo.write(180);
  delay(100);
}

void loop() {
  Buffer_Time = (millis()/1000);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds (10);
  digitalWrite(TRIG_PIN, LOW);
  int microsecs = pulseIn (ECHO_PIN, HIGH);
  float cms = microsecs*SPEED_OF_SOUND/2;
  Serial.println(Buffer_Time);
  
  if (cms < 7) {
    digitalWrite (MOTOR_PIN1, LOW);
    digitalWrite (MOTOR_PIN2, LOW);
    digitalWrite (MOTOR_PIN3, LOW);
    digitalWrite (MOTOR_PIN4, LOW);
    
    if (Buffer_Time > 10){
    delay(500);
    servo.write(20);
    }
    
  } else {
    servo.write(180);
    digitalWrite (MOTOR_PIN1, HIGH);
    digitalWrite (MOTOR_PIN2, HIGH);
    digitalWrite (MOTOR_PIN3, HIGH);
    digitalWrite (MOTOR_PIN4, HIGH);
  }
    delay(10);
}

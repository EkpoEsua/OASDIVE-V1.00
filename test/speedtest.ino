#include<Servo.h>

//#define sensor_1 0 //sensor 1 is connected to analag pin 0
//#define sensor_2 1 //sensor 2 is connected ro analog pin 1
#define forward 12 // set high to move vehicle forward
#define backward 13 // set high to move vehicle backward
#define sensor1Pin 3 //set pin 3 for sensor 1
#define sensor2Pin 2 //set pin 2 for sensor 2
#define sensor_trigger 4 //set sensor trigger to a pin to start sensing

//initialize the servo motors for each seperate object
Servo servo_1; //servo for sensor 1
Servo servo_2; //servo for sensor 2
Servo servo_3; //this is the servo for the wheeling the tyres
//
//set the rover's speed
int speed_1 = 5;
int speed_2 = 128;

// wheeling
#define left 50
#define right 130
#define centre 90

//infinite condition
int condition = 0;
unsigned long sensor1, sensor2;

void setup() {
//  //initialize output and input pins for the rovers sensors and actuators
//  servo_1.attach(9); //servo 1 is attached to digital pin 9
//  servo_2.attach(10); //servo 2 is attached to digital pin 10
//  servo_3.attach(11); //servo 3 is attached to digital pin 11
//
//  //sensor pins config
//  pinMode(sensor1Pin, INPUT);
//  pinMode(sensor2Pin, INPUT);
//  pinMode(sensor_trigger, OUTPUT);

  pinMode(forward, OUTPUT); //pin for moving the rover forward
  pinMode(backward, OUTPUT); //pin for moving the rover backward

  //wait for two seconds  
  delay(2000);

//  //initialize rover
//   
//  //set front tyres forward
//  servo_3.write(centre);
//  //set servo 1 and sensor 2 forward
//  servo_1.write(0);
//  servo_2.write(0);
//
//  //test wheelling
//  servo_3.write(left);
//  delay(1000);
//  servo_3.write(centre);
//  delay(1000);
//  servo_3.write(right);
//  delay(1000);
//  servo_3.write(centre);
//  delay(1000);
//
//  //test sensor positioning
//  servo_1.write(90);
//  delay(1000);
//  servo_1.write(0);
//  delay(1000);
//  servo_2.write(90);
//  delay(1000);
//  servo_2.write(0);
//  delay(1000);
// put your setup code here, to run once:
pinMode(forward, OUTPUT); //pin for moving the rover forward
pinMode(backward, OUTPUT); //pin for moving the rover backward

delay(2000);
move_forward();
delay(5000);
move_backward();
delay(5000);
move_forward();
delay(5000);
digitalWrite(backward,LOW);
}
void move_forward(){
  digitalWrite(backward, HIGH);
  digitalWrite(forward, LOW);
  //analogWrite(backward, speed_1);
}
void move_backward(){
  digitalWrite(forward, HIGH);
  digitalWrite(backward, LOW);
  delay(1000);
  //analogWrite(forward, speed_1);
}
void brake(){
  digitalWrite(forward,LOW);
  digitalWrite(backward,LOW);
  delay(2000); 
}

void loop() {
// put your main code here, to run repeatedly:  
}

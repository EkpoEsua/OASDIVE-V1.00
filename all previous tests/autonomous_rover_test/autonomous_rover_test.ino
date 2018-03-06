#include<Servo.h>

Servo servo_1;
Servo servo_3;

#define forward 5 // set high to move vehicle forward
#define backward 6 // set high to move vehicle backward

//set the rover's speed
#define speed_1 40
#define speed_2 100

int condition = 0;

#define sensor1Pin 3 //set pin 3 for sensor 1

unsigned long sensor1;

// wheeling
#define left 50
#define right 130
#define centre 90


void setup() {
  Serial.begin(9600);
  servo_1.attach(9);
  servo_3.attach(11);

  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  // initialize both motor output to LOW
  digitalWrite(forward, LOW);
  digitalWrite(backward, LOW);

  //set sensor pins
  pinMode(sensor1Pin, INPUT);

  //initialize rover

  //test wheelling
  servo_3.write(centre);
  delay(500);
  servo_3.write(left);
  delay(500);
  servo_3.write(centre);
  delay(500);
  servo_3.write(right);
  delay(500);
  servo_3.write(centre);
  delay(500);

  //test sensor servos
  //servo 1
  servo_1.write(0);
  delay(500);
  servo_1.write(90);
  delay(500);
  servo_1.write(180);
  delay(500);
  servo_1.write(90);
  delay(500);


}

void loop() {

  //obstacle test 1.0
  servo_1.write(90);
  read_sensor();
  while (sensor1 > 80) {
    read_sensor();
    //move forward
    move_forward();
  }
  brake();

  read_sensor();
  if (sensor1 < 30) {
    brake();
    servo_3.write(centre);
    delay(300);
    while (sensor1 < 80) {
      read_sensor();
      move_backward();
    }
    brake();
  }

  //check left for obstacle
  servo_1.write(0);
  delay(300);
  read_sensor();

  if (sensor1 > 80) {
    servo_3.write(left);
    servo_1.write(90);
    delay(300);
    read_sensor();
    while (sensor1 < 200) {
      read_sensor();
      thrust_forward();
      if (sensor1 < 30) {
        brake();
        servo_3.write(right);
        delay(300);
        while (sensor1 < 80) {
          read_sensor();
          move_backward();
        }
        brake();
        servo_3.write(left);
        delay(300);
      }
    }
    brake();
    goto point2;
  }
  servo_1.write(180);
  delay(300);
  read_sensor();

  if (sensor1 > 80) {
    servo_3.write(right);
    servo_1.write(90);
    delay(300);
    read_sensor();
    while (sensor1 < 200) {
      read_sensor();
      thrust_forward();
      if (sensor1 < 30) {
        brake();
        servo_3.write(left);
        delay(300);
        while (sensor1 < 80) {
          read_sensor();
          move_backward();
        }
        brake();
        servo_3.write(right);
        delay(300);
      }
    }
    brake();
    goto point2;
  }
  else {
    servo_1.write(90);
    servo_3.write(left);
    delay(300);
    read_sensor();
    while (sensor1 < 200) {
      read_sensor();
      move_backward();
    }
    brake();
    goto point2;
  }

point2:
  move_forward();
  delay(800);
  servo_1.write(90);
  servo_3.write(centre);
  //  while (sensor1 > 80) {
  //    read_sensor();
  //    //move forward
  //    move_forward();
  //  }
  //  brake();
}




void read_sensor () {
  sensor1 = pulseIn(sensor1Pin, HIGH);
  sensor1 = sensor1 / 58;
}

void move_forward() {
  digitalWrite(backward, LOW);
  analogWrite(forward, speed_2);
}

void move_backward() {
  digitalWrite(forward, LOW);
  analogWrite(backward, speed_1);
}

void brake() {
  digitalWrite(forward, LOW);
  digitalWrite(backward, LOW);
  delay(800);
}

void thrust_forward() {
  digitalWrite(backward, LOW);
  digitalWrite(forward, HIGH);
}


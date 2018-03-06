#include<Servo.h>

Servo servo_1;
Servo servo_3;

#define forward 5 // set high to move vehicle forward
#define backward 6 // set high to move vehicle backward

//set the rover's speed
#define speed_1 80
#define speed_2 100

#define sensor1Pin 3 //set pin 3 for sensor 1

// initializing variables for sensor measurements
unsigned short sensor1, sensor2, sensor3, sensor4;

// wheeling
#define left 50
#define right 130
#define centre 90

//setting definitions for sensor pins and trigger pins
#define centre_sensor 2
#define right_sensor 3
#define left_sensor 4
#define centre_sensor_trig 10
#define right_sensor_trig 12
#define left_sensor_trig 13
#define back_sensor 7
#define back_sensor_trig 8

void setup() {
  Serial.begin(9600);
  servo_1.attach(9);
  servo_3.attach(11);

  //set sensor and trigger pins
  pinMode(centre_sensor, INPUT);
  pinMode(centre_sensor_trig, OUTPUT);
  digitalWrite(centre_sensor_trig, LOW);

  pinMode(right_sensor, INPUT);
  pinMode(right_sensor_trig, OUTPUT);
  digitalWrite(right_sensor_trig, LOW);

  pinMode(left_sensor, INPUT);
  pinMode(left_sensor_trig, OUTPUT);
  digitalWrite(left_sensor_trig, LOW);

  pinMode(back_sensor, INPUT);
  pinMode(back_sensor_trig, OUTPUT);
  digitalWrite(back_sensor_trig, LOW);

  //set forward and backward pins for the motors
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);

  // initialize both motor output to LOW to stop
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
  // due to offsetting we are using 0, 80, and 160 deg instead of 0, 90 and 180 deg.

  servo_1.write(0);
  delay(500);
  servo_1.write(80);
  delay(500);
  servo_1.write(160);
  delay(500);
  servo_1.write(80);
  delay(500);

}

void loop() {

  //obstacle test 1.0
  servo_1.write(80);
  read_sensor();
  while (sensor1 > 70) {
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
    while (sensor1 < 30) {
      read_sensor();
      move_backward();
      if (sensor4 < 30) {
        break;
      }
    }
    brake();
  }

  //check left for obstacle
  servo_1.write(0);
  delay(300);
  read_sensor();

  if (sensor1 > 60) {
    servo_3.write(left);
    servo_1.write(80);
    delay(300);
    read_sensor();
    while (sensor1 < 80) {
      read_sensor();
      thrust_forward();
      if (sensor1 < 30) {
        brake();
        servo_3.write(right);
        delay(300);
        while (sensor1 < 80) {
          read_sensor();
          move_backward();
          if (sensor4 < 30) {
            break;
          }
        }
        brake();
        servo_3.write(left);
        delay(300);
      }
    }
    brake();
    goto point2;
  }
  servo_1.write(160);
  delay(300);
  read_sensor();

  if (sensor1 > 60) {
    servo_3.write(right);
    servo_1.write(80);
    delay(300);
    read_sensor();
    while (sensor1 < 100) {
      read_sensor();
      thrust_forward();
      if (sensor1 < 30) {
        brake();
        servo_3.write(left);
        delay(300);
        while (sensor1 < 60) {
          read_sensor();
          move_backward();
          if (sensor4 < 30) {
            break;
          }
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
    servo_1.write(80);
    servo_3.write(left);
    delay(300);
    read_sensor();
    while (sensor1 < 100) {
      read_sensor();
      move_backward();
      if (sensor4 < 30) {
        break;
      }
    }
    brake();
    goto point2;
  }

point2:

  servo_1.write(80);
  move_forward();
  delay(800);
  servo_3.write(centre);
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
  //delay(800);
}

void thrust_forward() {
  digitalWrite(backward, LOW);
  digitalWrite(forward, HIGH);
}

void read_sensor () {
  //trigger and read the centre sensor
  digitalWrite(centre_sensor_trig, HIGH);
  delayMicroseconds(21);
  digitalWrite(centre_sensor_trig, LOW);
  sensor1 = pulseIn(centre_sensor, HIGH);
  sensor1 = sensor1 / 58;

  //trigger and read the right sensor
  digitalWrite(right_sensor_trig, HIGH);
  delayMicroseconds(21);
  digitalWrite(right_sensor_trig, LOW);
  sensor2 = pulseIn(right_sensor, HIGH);
  sensor2 = sensor2 / 58;

  //trigger and read the left sensor
  digitalWrite(left_sensor_trig, HIGH);
  delayMicroseconds(21);
  digitalWrite(left_sensor_trig, LOW);
  sensor3 = pulseIn(left_sensor, HIGH);
  sensor3 = sensor3 / 58;

  //trigger and read the back sensor
  digitalWrite(back_sensor_trig, HIGH);
  delayMicroseconds(21);
  digitalWrite(back_sensor_trig, LOW);
  sensor4 = pulseIn(back_sensor, HIGH);
  sensor4 = sensor4 / 58;

}



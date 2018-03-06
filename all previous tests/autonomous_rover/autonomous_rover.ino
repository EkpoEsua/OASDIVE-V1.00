#include<Servo.h>

Servo servo_1;
Servo servo_3;

#define forward 5 // set high to move vehicle forward
#define backward 6 // set high to move vehicle backward

//set the rover's speed
#define speed_1 80
#define speed_2 100

int condition = 0;

#define sensor1Pin 3 //set pin 3 for sensor 1

unsigned long sensor1;

// wheeling
#define left 50
#define right 130
#define centre 90

//for HC-SR04 sensor
#define trigger_pin 7
#define echo_pin 8
#define trigger_pin_2 2
#define echo_pin_2 10

unsigned long sensor_a = 0;

void setup() {
  Serial.begin(9600);
  servo_1.attach(9);
  servo_3.attach(11);
  // for hc_sr04 sensor
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

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
      read_hc_sr04();
      if (sensor_a < 20) {
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
          read_hc_sr04();
          if (sensor_a < 20) {
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
          read_hc_sr04();
          if (sensor_a < 20) {
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
      read_hc_sr04();
      if (sensor_a < 20){
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

void read_hc_sr04() {
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(11);
  digitalWrite(trigger_pin, LOW);
  sensor_a = (pulseIn(echo_pin, HIGH)) / 58.2;

  //  digitalWrite(trigger_pin_2, HIGH);
  //  delayMicroseconds(11);
  //  digitalWrite(trigger_pin_2, LOW);
  //  sensor_b = (pulseIn(echo_pin_2, HIGH))/58.2;
}

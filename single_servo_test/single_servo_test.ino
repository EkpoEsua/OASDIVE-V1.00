#include<Servo.h>
Servo servo_1;


void setup() {
  servo_1.attach(9);
  delay(1000);
  servo_1.write(0);
  delay(1000);
  servo_1.write(80);
  delay(1000);
  servo_1.write(160);
  delay(1000);
  servo_1.write(80);
  delay(1000);
  
}
void loop() {
  // put your main code here, to run repeatedly:

}

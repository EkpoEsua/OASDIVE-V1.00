#include<Servo.h>

Servo servo;
 
  // wheeling
  #define left 50
  #define right 130
  #define centre 90


void setup() {
  servo.attach(11);

}

void loop(){
    
  //test wheelling
  servo.write(left);
  delay(1000);
  servo.write(centre);
  delay(1000);
  servo.write(right);
  delay(1000);
  servo.write(centre);
  delay(1000);
  

}

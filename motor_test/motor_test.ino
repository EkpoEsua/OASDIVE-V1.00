#define forward 5 // set high to move vehicle forward
#define backward 6 // set high to move vehicle backward

//set the rover's speed
#define speed_1 20
#define speed_2 128

void setup() {
  
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  // initialize both motor output to LOW
  digitalWrite(forward, LOW);
  digitalWrite(backward, LOW);


  //move rover forward
  move_forward();
  delay(2000);

  //Brake
  brake();

  //move rover backwards
  move_backward();
  delay(2000);
  brake();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void move_forward(){
  digitalWrite(backward, LOW);
  analogWrite(forward, speed_2);
}

void move_backward(){
  digitalWrite(forward, LOW);
  analogWrite(backward, speed_1);
}

void brake(){
  digitalWrite(forward,LOW);
  digitalWrite(backward,LOW);
  delay(2000); 
}


#define sensor1Pin 3 //set pin 3 for sensor 1
#define sensor2Pin 2 //set pin 2 for sensor 2
#define sensor_trigger 4 //set sensor trigger to a pin to start sensing

unsigned long sensor1, sensor2;

void setup() {
  Serial.begin(9600);
  //set sensor pins
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin,INPUT);

  //start triggering of sensors
  digitalWrite(sensor_trigger, HIGH);
  delayMicroseconds(25);
  digitalWrite(sensor_trigger,LOW);
  delayMicroseconds(10);
  pinMode(sensor_trigger, INPUT);
}

void loop() {
  read_sensor();
  Serial.print("sensor 1 = ");
  Serial.print(sensor1);
  Serial.print(" ");
  Serial.print("sensor 2 = ");
  Serial.println(sensor2);  
  delay(1000);
  // put your main code here, to run repeatedly:

}

void read_sensor (){
  sensor1 = pulseIn(sensor1Pin, HIGH);
  sensor1 = sensor1/58;
  sensor2 = pulseIn(sensor2Pin, HIGH);
  sensor2 = sensor2/58;
  
}

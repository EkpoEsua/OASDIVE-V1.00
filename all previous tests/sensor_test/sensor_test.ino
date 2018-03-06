#define sensor1Pin 3 //set pin 3 for sensor 1
#define sensor_trigger 4 //set sensor trigger to a pin to start sensing

unsigned long sensor1;

void setup() {
  Serial.begin(9600);
  //set sensor pins
  pinMode(sensor1Pin, INPUT);

}

void loop() {
  read_sensor();
  Serial.print("sensor 1 = ");
  Serial.println(sensor1);
  delay(1000);
  // put your main code here, to run repeatedly:

}

void read_sensor (){
  sensor1 = pulseIn(sensor1Pin, HIGH);
  sensor1 = sensor1/58;
  
}

//setting definitios for sensor pins and trigger pins
#define centre_sensor 2
#define right_sensor 3
#define left_sensor 4
#define centre_sensor_trig 10
#define right_sensor_trig 12
#define left_sensor_trig 13
#define back_sensor 7
#define back_sensor_trig 8

unsigned short sensor1, sensor2, sensor3, sensor4;

void setup() {
  Serial.begin(9600);

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
}

void loop() {
  //read and display sensor readings
  read_sensor();
  Serial.print("centre sensor = ");
  Serial.print(sensor1);

  Serial.print(" right sensor = ");
  Serial.print(sensor2);

  Serial.print(" left sensor = ");
  Serial.print(sensor3);
  
  Serial.print(" back sensor = ");
  Serial.println(sensor4);
  delay(1000);
  // put your main code here, to run repeatedly:

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

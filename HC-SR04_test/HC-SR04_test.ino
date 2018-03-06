#define trigger_pin 7
#define echo_pin 8
//#define trigger_pin_2 2
//#define echo_pin_2 10

unsigned long sensor_a = 0, sensor_b = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
//  pinMode(trigger_pin_2, OUTPUT);
//  pinMode(echo_pin_2, INPUT);

}

void loop() {
  read_hc_sr04();
  Serial.print("sensor_a = ");
  Serial.println(sensor_a);
//  Serial.print(" sensor_b = ");
//  Serial.println(sensor_b);
  delay(1000);
}

void read_hc_sr04(){
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(21);
  digitalWrite(trigger_pin, LOW);
  sensor_a = (pulseIn(echo_pin, HIGH))/58.2;
  
//  digitalWrite(trigger_pin_2, HIGH);
//  delayMicroseconds(11);
//  digitalWrite(trigger_pin_2, LOW);
//  sensor_b = (pulseIn(echo_pin_2, HIGH))/58.2;
}


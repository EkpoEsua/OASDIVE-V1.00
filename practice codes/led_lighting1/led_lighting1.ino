const int red = 9;
const int green = 10;
const int blue = 11;
int time = 500;

void setup() {
  // put your setup code here, to run once:
  // initializing pins
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);


}

void loop() {
  // to light up the pins of a three color LED continuously in a particular order:
  // all three pins swiched on
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  delay(400);
  // all pins off
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  delay (400);
  // two pins on
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  delay(time);
  // two pins on
  digitalWrite(red, HIGH);
  digitalWrite(blue, LOW);
  delay(time);
  //two pins on
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  delay(time);
}

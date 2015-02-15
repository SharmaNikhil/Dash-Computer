int led_pin = 8;
int input_pin = 10;
int pos_pin = 11;
int clock_pin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin,OUTPUT);
  pinMode(pos_pin,OUTPUT);
  pinMode(input_pin,INPUT); //Be sure to wire switches to ground
  pinMode(clock_pin,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Initialized");
}
boolean on = true;
int val = 0;
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pos_pin,HIGH);
  digitalWrite(clock_pin,on);
  on=!on;
  val = !digitalRead(input_pin);
  Serial.println(val);
  digitalWrite(led_pin,val);
  delay(50);
}

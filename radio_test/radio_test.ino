int pin_input = 8;
int pin_output = 9;
int pin_ind = 10;
int pin_ind_on = 11;

int cycle_time = 250; //ms

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_input,INPUT);
  pinMode(pin_output,OUTPUT);
  pinMode(pin_ind,OUTPUT);
  Serial.begin(9600);
}

int val = 0; //reading variable

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_output,LOW);
  digitalWrite(pin_ind,LOW);
  
  val=digitalRead(pin_input);
  Serial.println(val);
  
  digitalWrite(pin_output,val);
  digitalWrite(pin_ind,!val);
  
  delay(cycle_time);
}

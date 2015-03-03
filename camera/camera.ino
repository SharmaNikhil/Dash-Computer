//camera.ino

int pin_out_switch = 8; //triggers the switch (power to camera)
//int pin_out_rf = 8; //rf receiver power
int pin_out_ind_g = 10;
int pin_out_ind_r = 11;
int pin_in_rf = 7; //rf signal

int time_cycle = 50; //time per cycles
int time_rled_on = time_cycle/2;
int time_rled_off = time_cycle-time_rled_on;
int time_switch_trigger = time_rled_on; //time to trigger switch, SET TO 1 SECONDS FOR TESTING, SET TO 60 FOR FINAL

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_out_switch,OUTPUT);
//  pinMode(pin_out_rf,OUTPUT);
  pinMode(pin_out_ind_g,OUTPUT);
  pinMode(pin_out_ind_r,OUTPUT);
  pinMode(pin_in_rf,INPUT);
  
  Serial.begin(9600);
  digitalWrite(pin_out_ind_r,HIGH);
  while(Serial.available() < 1){}
//  Serial.println("Set up");
}

int input = 0;
int c = 0;
void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("*********** BEGIN CYCLE ***********");
  digitalWrite(pin_in_rf,HIGH);
  c++;
//  digitalWrite(pin_out_rf,HIGH);
//  Serial.println("RF on");
  delay(5);
  input=digitalRead(pin_in_rf);
//  Serial.print("RF val: ");
//  Serial.print(c);
//  Serial.print(", ");
//  if(input)
//    Serial.print("*");
//  else 
//    Serial.print("_");
  Serial.print(input);
  Serial.print(" ");
//  digitalWrite(pin_out_rf,LOW);
//  Serial.println("RF off");
  
  if(input==HIGH){
//    Serial.println("input on");
    digitalWrite(pin_out_ind_g,HIGH);
    digitalWrite(pin_out_switch,HIGH);
//    Serial.println("pin_out_switch on");
    delay(time_switch_trigger);
    digitalWrite(pin_out_ind_g,LOW);
    digitalWrite(pin_out_switch,LOW);
//    Serial.println("pin_out_switch off");
  }
  else{
//    Serial.println("input off");
    digitalWrite(pin_out_ind_r,HIGH);
    delay(time_rled_on);
    digitalWrite(pin_out_ind_r,LOW);
    delay(time_rled_off);
  }
//  Serial.println("*********** END CYCLE ***********");
}

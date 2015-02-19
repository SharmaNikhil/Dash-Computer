int pin_out_switch = 7; //triggers the switch (power to camera)
int pin_out_rf = 8; //rf receiver power
int pin_out_ind_g = 10;
int pin_out_ind_r = 11;
int pin_in_rf = 9; //rf signal

int time_cycle = 500; //time per cycles
int time_rled_on = 250;
int time_rled_off = time_cycle-time_rled_on;
int time_switch_trigger = 5000; //time to trigger switch, SET TO 5 SECONDS FOR TESTING, SET TO 60 FOR FINAL

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_out_switch,OUTPUT);
  pinMode(pin_out_rf,OUTPUT);
  pinMode(pin_out_ind_g,OUTPUT);
  pinMode(pin_out_ind_r,OUTPUT);
  pinMode(pin_in_rf,INPUT);
  
  Serial.begin(9600);
}

int input = 0;
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_out_rf,HIGH);
  Serial.println("RF on");
  input=digitalRead(pin_in_rf);
  Serial.println("RF val:"+input);
  digitalWrite(pin_out_rf,LOW);
  Serial.println("RF off");
  
  if(input){
    Serial.println("input on");
    digitalWrite(pin_out_ind_g,HIGH);
    digitalWrite(pin_out_switch);
    Serial.println("pin_out_switch on");
    delay(time_switch_trigger);
    digitalWrite(pin_out_ind_g,LOW);
    digitalWrite(pin_out_switch,LOW);
    Serial.println("pin_out_switch off");
  }
  else{
    Serial.println("input off");
    digitalWrite(pin_out_ind_r,HIGH);
    delay(time_rled_on);
    digitalWrite(pin_out_ind_r,LOW);
    delay(time_rled_off);
  }
}

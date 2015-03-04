//camera.ino
//v0.0

int pin_out_switch = 8; //triggers the switch (power to camera)
int pin_out_rf = 9; //rf receiver power
int pin_out_ind_g = 10;
int pin_out_ind_r = 11;
int pin_in_rf = 7; //rf signal

int time_cycle = 50; //time per cycles
int time_rled_on = 5; //must be < time_cycle else will be reset to 0.5*time_cycle
int time_rled_off = time_cycle-time_rled_on;
int time_switch_trigger = time_rled_on; //time to trigger switch, SET TO 1 SECONDS FOR TESTING, SET TO 60 FOR FINAL

void setup() {
  // put your setup code here, to run once:
  if(time_rled_on<time_cycle) time_rled_on=time_cycle/2;
  
  pinMode(pin_out_switch,OUTPUT);
  pinMode(pin_out_rf,OUTPUT);
  pinMode(pin_out_ind_g,OUTPUT);
  pinMode(pin_out_ind_r,OUTPUT);
  pinMode(pin_in_rf,INPUT);
  
  Serial.begin(9600);
  Serial.println("Setup complete. Waiting for any serial input.");
  while(!Serial.available()){}
}

int input = 0;
int c = 0; //loop count
void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print("*********** BEGIN CYCLE ");
  Serial.print(c);
  Serial.println("***********");
  
  c++;
  digitalWrite(pin_out_rf,HIGH);
  Serial.println("Reading RF");
  input=digitalRead(pin_in_rf);
  if(input) Serial.println("RF input HIGH"); else Serial.println("RF input LOW");
  digitalWrite(pin_out_rf,LOW);
  
  if(input==HIGH){
    Serial.println("input on");
    digitalWrite(pin_out_ind_g,HIGH);
    digitalWrite(pin_out_switch,HIGH);
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
  Serial.print("*********** END CYCLE ");
  Serial.print(c);
  Serial.println("***********");
}

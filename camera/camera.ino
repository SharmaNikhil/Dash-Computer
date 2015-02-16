int pin_out_switch = 7; //triggers the switch (power to camera)
int pin_out_rf = 8; //rf receiver power
int pin_out_ind_g = 10;
int pin_out_ind_r = 11;
int pin_in_rf = 9; //rf signal

int time_cycle_wait = 50; //time between cycles
int time_rf_on = 50;
int time_rf_off = 1000-time_rf_on-cycle_wait_time;
int time_switch_trigger = 5000; //time to trigger switch, SET TO 5 SECONDS FOR TESTING, SET TO 60 FOR FINAL

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_out_switch,OUTPUT);
  pinMode(pin_out_rf,OUTPUT);
  pinMode(pin_out_ind_g,OUTPUT);
  pinMode(pin_out_ind_r,OUTPUT);
  pinMode(pin_in,rf,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //1 loop = 1 second
  
}

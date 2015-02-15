int pin_led= 8;    //output to LED
int pin_input=9;   //input from radio
int pin_output=10; //output to toggle power to camera

int loop_time=100; //time delay at the end of each loop
int on_time=500; //TODO change to 60s (60000)

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_led,OUTPUT);
  pinMode(pin_input,INPUT);
  pinMode(pin_output,OUTPUT);
  Serial.begin(9600);
  Serial.println("Initialize");
}
int toggleled=1;
int val=0;
int count=0;
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin_led,toggleled);
  toggleled=!toggleled;
  
  val=!digitalRead(pin_input);
//  Serial.println("val: "+val);
  if(val){
    Serial.println(count);
    count=0;
    val=0;
//    Serial.println("input high");
    digitalWrite(pin_output,HIGH);
//    Serial.println("output high");
//    delay(on_time); //TODO non-shitty solution
    digitalWrite(pin_output,LOW);
//    Serial.println("output low");
  } 
  else{
    count++;
  }
  delay(loop_time);
}

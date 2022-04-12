const unsigned char Active_buzzer = 14;

void setup(){
  pinMode(Active_buzzer,OUTPUT); 
}
void loop(){
  digitalWrite(Active_buzzer,HIGH);
  delay(1000);
}

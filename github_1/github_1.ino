String TEXT;
void setup() {
Serial.begin(9600);
pinMode(6, OUTPUT);    //NIGHT LAMP PIN
pinMode(4, OUTPUT);   // LED PIN
pinMode(9, OUTPUT);     // MOTOR PIN 1
pinMode(10, OUTPUT);     //MOTOR PIN 2
}

void loop() {

  while(Serial.available())
  {
  delay(3);
  char c = Serial.read();
  TEXT+=c;
  }

if(TEXT.length() >0){
  
  Serial.println(TEXT);
  
  if(TEXT == "light on")
  {digitalWrite(6, HIGH);}
  
  else if(TEXT == "light off")
  {digitalWrite(6, LOW);}
  
  else if(TEXT == "fan on")
  {
    digitalWrite(9, 1);
    digitalWrite(10,0);
  }

  else if(TEXT == "fan off")
  {
   digitalWrite(9, 0);
    digitalWrite(10,0);
  }
  
  else if(TEXT == "night lamp on")
  {digitalWrite(4, HIGH);}
  
  
  else if(TEXT == "night lamp off")
  {digitalWrite(4, LOW);}
  
  
  else if(TEXT == "all on")
  {digitalWrite(4, HIGH);
   digitalWrite(9, 1);
    digitalWrite(10,0);
  digitalWrite(6, HIGH);}

  
  else if(TEXT == "all off")
  {digitalWrite(4, LOW);
    digitalWrite(9, 0);
    digitalWrite(10,0);
  
  digitalWrite(6, LOW);}
  TEXT = "";}
}

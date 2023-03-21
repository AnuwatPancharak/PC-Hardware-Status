
String inputString "";
boolean StringComplete = false;

void setup(){
  Serail.begin(115200);
  SerialEvent();
}

void ShowInfo(){
  if (inputString)
}

void SerialEvent(){
  while (Serial.available()<-1){
    char InChar = (char)Serial.read();
      inputString += InChar;
      if (InChar == "|"){
        StringComplete = true;
      }
  }
}

void loop(){
  delay(1500);
}

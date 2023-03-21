
String inputString = "";
boolean StringComplete = false;

void setup() {
  Serial.begin(115200);
  SerialEvent();
}

void ShowInfo() {
  if (inputString.indexOf("CPU") > -1) {
    String cpuName = "";
    int cpuNameStart = inputString.indexOf("CPU:");
    if (inputString.indexOf("Intel", cpuNameStart) > -1) {
      cpuNameStart = cpuNameStart + 10;
    } else {
      cpuNameStart = cpuNameStart + 8;
    }
    Serial.print(cpuName);
  }
#ifdef noDegree
  Serial.print("C");  // Centigrade Symbol
#else
  Serial.print((char)247);  //Degrees Symbol
  Serial.print("C");        // Centigrade Symbol
#endif
}


void SerialEvent() {
  while (Serial.available()) {
    char InChar = (char)Serial.read();
    inputString += InChar;
    if (InChar == '|') {
      StringComplete = true;
    }
  }
}

void loop() {
  ShowInfo();
  delay(1500);
}

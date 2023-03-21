String inputString = "";
boolean stringComplete = false;

void setup() {
  Serial.setTimeout(100);
  Serial.begin(115200);
  serialEvent();
}
void DisplayStyle1() {
  if (inputString.indexOf("CPU") > -1) {
    String cpuName = "";
    int cpuNameStart = inputString.indexOf("CPU:");
    if (inputString.indexOf("Intel", cpuNameStart) > -1) {
      cpuNameStart = cpuNameStart + 10;
    } else {
      cpuNameStart = cpuNameStart + 8;
    }
    if (inputString.indexOf("GPU") > -1) {
      cpuName = inputString.substring(cpuNameStart, inputString.indexOf("GPU:"));
    } else
      cpuName = inputString.substring(cpuNameStart);
    Serial.println(cpuName);
  }
  /*CPU Display String*/
  int cpuStringStart = inputString.indexOf("C");
  int cpuDegree = inputString.indexOf("c");
  int cpuStringLimit = inputString.indexOf("|");
  String cpuString1 = inputString.substring(cpuStringStart + 1, cpuDegree);
  String cpuString2 = inputString.substring(cpuDegree + 1, cpuStringLimit - 1);

  /*CPU TEMPERATURE*/
  Serial.print(cpuString1);

#ifdef noDegree
  Serial.print("C");  // Centigrade Symbol
#else
  Serial.print((char)247);  //Degrees Symbol
  Serial.print("C");        // Centigrade Symbol
#endif

  /*CPU LOAD, ALL CORES*/

  Serial.print(cpuString2);
  Serial.println("%");  // Small Percent Symbol
}
void serialEvent() {

  while (Serial.available()) {          //  32u4 USB Serial Available?
    char inChar = (char)Serial.read();  // Read 32u4 USB Serial
    Serial.print(inChar); // Debug Incoming Serial

    inputString += inChar;
    if (inChar == '|') {
      stringComplete = true;
    }
  }
}
void loop() {
  DisplayStyle1();
  delay(1000);
}
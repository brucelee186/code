int pinLM35D = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  // 0代表模拟A0端口
  int temperatureVoltage = analogRead(A0);

  float temperature = temperatureVoltage*(5.0 / 1023.0 * 100);
  Serial.println(temperature);
  delay(1000);
}

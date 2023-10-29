#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3zF0FU3zb"
#define BLYNK_TEMPLATE_NAME "Air Quality monitoring"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char ssid[] = "realme C11";
char pass[] = "rithi:phone";
char auth[] = "EoLmcK6ndDCfQTko9ANZUljdtyP2GMud";
BlynkTimer timer;
int pinValue = 0;
#define Green D6
#define Red D8
#define Sensor A0

void setup() {
  Serial.begin(115200);
  pinMode(Green, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Sensor, INPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, notification);
}

BLYNK_WRITE(V0) {
  pinValue = param.asInt();
}

void notification() {
  int sensor = analogRead(Sensor);
  Serial.println(sensor);

  if (sensor < 100) {
    digitalWrite(Green, HIGH);
    digitalWrite(Red, LOW);
  } else {
    // Send a high gas level notification to Virtual Pin V2
    Blynk.virtualWrite(V2, 1);
    digitalWrite(Green, LOW);
    digitalWrite(Red, HIGH);
  }
  Blynk.virtualWrite(V1, sensor);
}

void loop() {
  Blynk.run();
  timer.run();
}

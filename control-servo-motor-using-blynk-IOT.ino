//In Blynk two web dashboards are used 1) Slider 2)Gauge(used to see the servo motors output i.e degree of rotation)
//0-180 deg is used in both the dashboard
//pins Virtual pins
#define BLYNK_TEMPLATE_ID "TMPL3U5hsR682"
#define BLYNK_TEMPLATE_NAME "Control Servo Motor"
#define BLYNK_AUTH_TOKEN "s1DnjO7SVfrjN3DsnEsTlyzSJ43tFI7u"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include<Servo.h>
Servo servo1;

char auth[] = "s1DnjO7SVfrjN3DsnEsTlyzSJ43tFI7u";
char ssid[] = "Device name";
char pass[] = "Device password";

BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  servo1.write(s0);
  Blynk.virtualWrite(V1, s0);
} 

void setup()
{
  Serial.begin(9600);
  servo1.attach(D2); //Connect to Pin D2 in NodeMCU
  Blynk.begin(auth, ssid, pass);//Splash screen delay
  delay(2000); 
}

void loop() 
{
  Blynk.run();
}

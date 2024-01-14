#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3rOtt4Hcw"
#define BLYNK_TEMPLATE_NAME "Control Bulb"
#define BLYNK_AUTH_TOKEN "oc1GTSFoz6ugcxsMO-z2cLl6vuKHKUC5"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Jackdorby";
char pass[] = "12345677";

void setup()
{

  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}


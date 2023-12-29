//Blynk constants
#define BLYNK_TEMPLATE_ID "TMPL3MOhkkHS4"
#define BLYNK_TEMPLATE_NAME "Control LED"//provided by the user while creating template
#define BLYNK_AUTH_TOKEN "NVBdZ9RL-EB0nMqUSO5j1NarUy_n-9R3" //Authentication token used to connect the device to the Blynk server

#define BLYNK_PRINT Serial//Extablishing communication between the device and the Blynk server.
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>
 

char auth[] = "NVBdZ9RL-EB0nMqUSO5j1NarUy_n-9R3";
char ssid[] = "device name";  // Enter your Wifi Username 
char pass[] = "device password";  // Enter your Wifi password

int ledpin = D4;
void setup()//The setup function is called once when the device starts.
{     
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(ledpin,OUTPUT);
}

void loop()
{
  Blynk.run(); 
}

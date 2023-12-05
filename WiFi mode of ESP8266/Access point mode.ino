#include<ESP8266WiFi.h>
#include<DNSServer.h>
#include<WiFiManager.h>
WiFiManager wifi;
void setup()
{
Serial.begin(115200);
wifi.autoConnect("Rithanya's Hotspot Area");
Serial.println("connected to Hotspot Area");
}
void loop()
{
    
}

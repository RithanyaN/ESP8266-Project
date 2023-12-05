#include<ESP8266WiFi.h>
#include<DNSServer.h>
#include<WiFiManager.h>
WiFiManager wifi;//wifi object of WiFiManager
void setup()
{
Serial.begin(115200);
wifi.autoConnect("Rithanya's Hotspot Area");//Creating the hotspot-area manually if not available and providing the internet to it via Wifi Manager
Serial.println("connected to Hotspot Area");
}
void loop()
{
    
}

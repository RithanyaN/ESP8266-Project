#include<ESP8266WiFi.h>
void WiFiConnection();
void setup()
{
  Serial.begin(9600);
  WiFiConnection();
}

void loop() {
  // put your main code here, to run repeatedly:

}
void WiFiConnection()
{
  WiFi.mode(WIFI_STA);  //Connecting ESP8266 via Station mode
  WiFi.begin("devicename","password");
  Serial.print("Connecting to WiFi"); 
  //WiFi.status will return the WL_CONNECTED when it is connected to the WiFi router if not print the folloeing satus
  while(WiFi.status()!=WL_CONNECTED)  
  {
    Serial.println("Trying to connect to WiFi");
    delay(100);
  }
  Serial.print("IP Adress:");
  Serial.print(WiFi.localIP());
  Serial.print("MacAddress");
  Serial.print(WiFi.macAddress());
}

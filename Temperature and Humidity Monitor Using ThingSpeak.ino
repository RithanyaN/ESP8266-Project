#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>
#include<DHT.h>
#define DHTPIN 4 //connect to D2
void WiFiConnection();
WiFiClient client;
HTTPClient http;
void setup()
{
   Serial.begin(9600);
   WiFiConnection();

}
DHT dht(DHTPIN,DHT11);
void loop()
{
  dht.begin();
  float t=dht.readTemperature();
  float h=dht.readHumidity();
  int httpcode;
  String url="http://api.thingspeak.com/update?api_key=API_KEY0&field1=";//provide your API_KEY which was obtained from GET request
  url=url+t;
  http.begin(client,url);
  httpcode=http.GET();//always 200 or +ve
  if(httpcode>0)
  {
    Serial.print("Temperature:");
    Serial.println(t);
    Serial.print("data sent sucessfully");
  }
  else
  {
    Serial.println("Error");
  }
  url="http://api.thingspeak.com/update?api_key=Z33KYTTFPO3RLE40&field2=";
  url=url+h;
  http.begin(client,url);
  httpcode=http.GET();
  if(httpcode>0)
  {
    Serial.print("Humidity:");
    Serial.print(h);
    Serial.print("data sent sucessfully");
  }
  else
  {
    Serial.println("Error");
  }
  http.end();//diconnecting connection between client and the server
  delay(1000);
    
}
void WiFiConnection()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin("devicename","password");
  if(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("Not connected to WiFi");
    delay(500);
  }
  Serial.println("IP Address");
  Serial.println(WiFi.localIP());
}

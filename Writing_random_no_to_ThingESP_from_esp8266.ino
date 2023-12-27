#include<ESP8266WiFi.h>//to extablish the wifi connection
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>
WiFiClient client; //object of #include<WiFiClient.h>
HTTPClient http;  //object of #include<ESP8266HTTPClient.h>
void WiFiConnection();
void setup()
{
  Serial.begin(9600);
  WiFiConnection();
}
int httpcode,randomno;
String url,API="4XTHT2F22LDGVJ9T",FieldNo="1";//dynamic
void loop() 
{
  randomno=random(600,1000);//random number generated for every loopin between 1-99
  SendGETRequest(randomno);
}
void SendGETRequest(int data)
{
  // http.begin(client,"http://api.thingspeak.com/update?api_key=4XTHT2F22LDGVJ9T&field1=72");-direct uploading of constant data
  url="http://api.thingspeak.com/update?api_key=";
  url=url+API;
  url=url+"&field";
  url=url+FieldNo;
  url=url+"=";
  url=url+data;
  http.begin(client,url);
  Serial.println("Waiting for response");
  httpcode=http.GET();//always 200 or +ve
  if(httpcode>0)
  {
    Serial.println(data);
    Serial.print("data sent sucessfully");
  }
  else
  {
    Serial.println("Error");
  }
  http.end();//diconnecting connection between client and the server
  delay(16000); //for free account in thingspeak a data can be loaded for every 16sec
}
void WiFiConnection()
{
  WiFi.mode(WIFI_STA);  //Connecting ESP8266 via Station mode
  WiFi.begin(device_name,pass);
  Serial.print("Connecting to WiFi"); 
  //WiFi.status will return the WL_CONNECTED when it is connected to the WiFi router if not print the following satus
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

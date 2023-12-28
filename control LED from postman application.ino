#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>
HTTPClient http;
WiFiClient client;
String result,response;

void setup() 
{
  Serial.begin(9600);
  WiFiConnection();  
  pinMode(D0,OUTPUT);

}
void loop()
{
  String s=getcommand();
  if(s=="L1")
  {
    digitalWrite(D0,HIGH);
    Serial.println("LED IS HIGH");
  }
  else if(s=="L2")
  {
    digitalWrite(D0,LOW);
    Serial.print("LED IS LOW");
  }
 else
   {
  Serial.print("Invalid command received !!");
  }
   delay(10000);
}
String getcommand() 
{
  http.begin(client,"https://api.thingspeak.com/talkbacks/50958/commands/39056004.json?api_key=XCPDKOLELB3ZH744");
  int httpcode=http.GET();
  if(httpcode>0)
  {
    response=http.getString();
    Serial.println(response);
    int start_index=response.indexOf("command_string\":\"")+17;
    result=response.substring(start_index,start_index+2);
    Serial.print(result);
  }
  else
  {
    Serial.println("Failed to connect to server");
    http.end();
  }
  return result;


}
void WiFiConnection()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin("device name","password");
  Serial.print("Connecting to wifi");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.println("NOT Connected to wifi");
  }
  Serial.println("Local IP");
  Serial.println(WiFi.localIP());
}

#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
 #include <ESP8266HTTPClient.h>
  #include<ESP8266WebServer.h>
  #include <WiFiClient.h>

SoftwareSerial s(D6,D5);
const char* ssid     = "CPH1801";
const char* password = "987654321";
const char* host = "realtimepassenger.000webhostapp.com";
int data = 0 ;
const int api_key = 2345678;
const int bus_number = 433;
void setup() {
s.begin(9600);
Serial.begin(9600);
 delay(100);
 WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}
 
void loop() {
  
  if (s.available()>0)
  {
    data=s.read();
    Serial.println(data);
    
  Serial.print("connecting to ");
  Serial.println(host);

  

  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  String url = "/poist.php?api_key="+ String(api_key)+ "&bus_number="+ String(bus_number)+  "&no_passenger="+ String(data);
  
  
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
  }
 
 
 
}

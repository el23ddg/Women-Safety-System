#include <WiFi.h>
int incom;
const int WiFi_led = 2;
const char* ssid = "admin";
const char* password = "123456789";
String Lat, Lon, student2; 
int Status=0;
const char *server = "maker.ifttt.com";
const char* resource = "/trigger/alert/with/key/cFWuavj1soCooaCzgrgIt1";
void setup() {
  Serial.begin(115200);
  pinMode(34, INPUT);
  pinMode(WiFi_led, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(WiFi_led, HIGH);
    delay(500);
     digitalWrite(WiFi_led, LOW);
     delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
   if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(WiFi_led, HIGH);
    //Serial.print("LED High");
  }
}
void loop() {
  int incom=digitalRead(34);
  Serial.println(incom);
  if(incom==0 && Status==0)
  {
    makeIFTTTRequest();
    Status=1;
  }
 if(incom==1 ){Status=0;}
 delay(100);
}
void makeIFTTTRequest() {
  Serial.print("Connecting to "); 
  Serial.print(server);  
  WiFiClient client;
  int retries = 5;
  while(!!!client.connect(server, 80) && (retries-- > 0)) {
    Serial.print(".");
  }
  Serial.println();
  if(!!!client.connected()) {
    Serial.println("Failed to connect...");
  }  
  Serial.print("Request resource: "); 
  Serial.println(resource);
  // Temperature in Celsius
 // String jsonObject = String("{\"value1\":\"") + student + "\"}";
 String jsonObject = String("{\"value1\":\"") + Lat + "\",\"value2\":\"" + Lon + "\",\"value3\":\"" + student2 + "\"}";                                           
  client.println(String("POST ") + resource + " HTTP/1.1");
  client.println(String("Host: ") + server); 
  client.println("Connection: close\r\nContent-Type: application/json");
  client.print("Content-Length: ");
  client.println(jsonObject.length());
  client.println();
  client.println(jsonObject);        
  int timeout = 5 * 10; // 5 seconds             
  while(!!!client.available() && (timeout-- > 0)){
    delay(100);
  }
  if(!!!client.available()) {
    Serial.println("No response...");
  }
  while(client.available()){
    Serial.write(client.read());
  }  
  Serial.println("\nclosing connection");
  client.stop(); 
}

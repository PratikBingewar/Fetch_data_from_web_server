#include <HttpClient.h>
#include <WiFi.h>


const char* ssid     = "pratik";
const char* password = "pratik123";


void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting to WiFi....");
  }

  Serial.println("");
  Serial.println("WiFi connected !!!!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  if(WiFi.status() == WL_CONNECTED)

  HTTPClient http;
 
  http.begin("https://eatfit223.000webhostapp.com/volley/texTospeech_getUserDetails.php"); //Specify destination for HTTP request

  http.addHeader("Content-Type", "text/plain"); //Specify content-type header

  int httpResponseCode = http.POST("1");   //Send the actual POST request
 
   if(httpResponseCode>0){
 
    String response = http.getString();                       //Get the response to the request
 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
   }else{
 
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
 
   }
 
   http.end();  //Free resources
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(10000);  //Send a request every 10 seconds
 
}

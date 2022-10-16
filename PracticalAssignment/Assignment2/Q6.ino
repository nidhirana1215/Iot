//Que:-6 Write a program to communicate client and server through API. Fetch the led status value from database through php API and ON/OFF the LED or ON/OFF the Buzzer as per status value in a Database.


#include <Arduino.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

//#define Serial Serial

WiFiMulti wifiMulti;
WiFiServer server;


void setup() {

    pinMode(2, OUTPUT);
    
    Serial.begin(9600);

    Serial.println();
    Serial.println();
    Serial.println();

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    wifiMulti.addAP("Nidhu..", "redmi123");
    wifiMulti.run();
      if(wifiMulti.run() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
    }
     server.begin();
}

void loop() {
    // wait for WiFi connection
    if((wifiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        Serial.print("[HTTP] begin...\n");
        
       //HTTP // configure traged server and url
        http.begin("https://uranian-binders.000webhostapp.com/iotexample/fetch.php?name=led");
        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();
        Serial.println("httpcode"+ httpCode);
        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                Serial.println(payload);
                if (payload == "1") {
                  digitalWrite(2, HIGH);
                  Serial.println("LED/Buzzer ON");
                } else if (payload == "0") {
                  digitalWrite(2, LOW);
                  Serial.println("LED/Buzzer OFF");
                }
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }

    delay(500);
}

#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID "123"
#define WIFI_PASSWORD "11111111"
#define API_KEY "AIzaSyC-mHNOM1cUsizZqeMH9YzmyiKAljTO6pI"
#define DATABASE_URL "https://ecoenzym-d56ec-default-rtdb.asia-southeast1.firebasedatabase.app"

// Sensor pin definitions
const int MQGas_AO = 13;
const int MQ131_AO = 35;
const int pH_AO = 34;
const int ProbeTemp_Data = 23;

FirebaseData fdbo;
FirebaseAuth auth;
FirebaseConfig config;

const long utcOffsetInSeconds = 3600;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "asia.pool.ntp.org", utcOffsetInSeconds);
String dateTime;
unsigned long sendDataPrevMillis = 0;
bool signupOK = false;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected");

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  if (Firebase.signUp(&config, &auth, "", "")) {
    signupOK = true;
  }
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  timeClient.begin();
}

String getFormattedDate() {
  timeClient.update();
  unsigned long epochTime = timeClient.getEpochTime();
  struct tm *ptm = localtime((const time_t *)&epochTime); // Changed from gmtime to localtime
  
  char dateBuffer[30]; // Buffer to hold the formatted date and time
  // Format date and time: "02 Maret 2024 10:24"
  strftime(dateBuffer, sizeof(dateBuffer), "%d %B %Y %H:%M", ptm);
  return String(dateBuffer);
}

void loop() {

    sendDataPrevMillis = millis();

    // Get formatted date and time
    dateTime = "data1/" + getFormattedDate();
    
    // Read sensors
    float mqGasValue = analogRead(MQGas_AO);
    float mq131Value = analogRead(MQ131_AO);
    float pHValue = analogRead(pH_AO);
    // Temp reading simulation
    float tempValue = 25.0; // Placeholder for actual temperature sensor reading

    // Send data to Firebase
    if (Firebase.ready() && signupOK) {
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/MQGas", mqGasValue);
      Serial.println("Data Alcohol Terupload");
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/MQ131", mq131Value);
      Serial.println("Data Ozon Terupload");
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/pH", pHValue);
      Serial.println("Data pH Terupload");
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/Temperature", tempValue);
      Serial.println("Data Temperature Terupload");
    }
    
    Serial.println("------------------------------------------------");
    Serial.print("Sensor Alcohol : ");
    Serial.println(mqGasValue);
    Serial.print("Sensor Ozon : ");
    Serial.println(mq131Value);
    Serial.print("Sensor pH : ");
    Serial.println(pHValue);
    Serial.print("Sensor Temperatur : ");
    Serial.println(tempValue);
    delay(5000);
}

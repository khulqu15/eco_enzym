#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID "GH D-Team"
#define WIFI_PASSWORD "Jancokcokasulah"
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
  }

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
  struct tm *ptm = localtime(&epochTime); // Changed from gmtime to localtime
  
  char dateBuffer[30]; // Buffer to hold the formatted date and time
  // Format date and time: "20 Maret 2024 10:24"
  strftime(dateBuffer, sizeof(dateBuffer), "%d %B %Y %H:%M", ptm);
  return String(dateBuffer);
}

void loop() {
  if ((millis() - sendDataPrevMillis > 15000) || (sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();

    // Get formatted date and time
    dateTime = "data/" + getFormattedDate();
    
    // Read sensors
    float mqGasValue = analogRead(MQGas_AO);
    float mq131Value = analogRead(MQ131_AO);
    float pHValue = analogRead(pH_AO);
    // Temp reading simulation
    float tempValue = 25.0; // Placeholder for actual temperature sensor reading

    // Send data to Firebase
    if (Firebase.ready() && signupOK) {
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/MQGas", mqGasValue);
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/MQ131", mq131Value);
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/pH", pHValue);
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/Temperature", tempValue);
    }
  }
}

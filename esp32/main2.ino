#include <OneWire.h>
#include <DallasTemperature.h>
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

// pH sensor
float voltage, ph_Value = 25;
float acidVoltage    = 1990;   // 1990 buffer solution 4.0 at 25cX
float neutralVoltage  = 1460;  // 1460 buffer solution 7.0 at 25c

// Temp sensor
float temperature;
OneWire oneWire(ProbeTemp_Data);
DallasTemperature sensor(&oneWire);

// Connect database
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
    
    // pH sensor
    voltage = analogRead(pH_AO)/4095.0 * 3300;  // read the voltage
    float slope = (7.0-4.0)/((neutralVoltage-1500)/3.0 - (acidVoltage-1500)/3.0); 
    float intercept = 7.0 - slope*(neutralVoltage-1500)/3.0;
    ph_Value = slope*(voltage-1500)/3.0 + intercept;  // y=k*x+b 
    float pHValue = ph_Value;
    
    // Temp reading simulation
    sensor.requestTemperatures();
    temperature = sensor.getTempCByIndex(0); 
    float tempValue = temperature;

    // Send data to Firebase
    if (Firebase.ready() && signupOK) {
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/MQGas", mqGasValue);
      Serial.print("Data Alcohol Terupload");
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/MQ131", mq131Value);
      Serial.print(" Data Ozon Terupload");
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/pH", pHValue);
      Serial.print(" Data pH Terupload");
      Firebase.RTDB.setFloat(&fdbo, dateTime + "/Temperature", tempValue);
      Serial.print(" Data Temperature Terupload ");
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

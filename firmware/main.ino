#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <DHT.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
// WiFi Details
#define WIFI_SSID "OnePlus Nord CE4 Lite 5G"
#define WIFI_PASSWORD "MYpass@123"
// Firebase Details
#define API_KEY "AIzaSyCn697xTLvtC7Y2tQEvaTrWPwIB6bP3tjE"
#define DATABASE_URL "https://nexus4-39b9c-default-rtdb.firebaseio.com/"
#define USER_EMAIL "ishanjijigeorge2026@ec.ajce.in"
#define USER_PASSWORD "MYpassword@1234"
// Pins
#define DHTPIN 4
#define DHTTYPE DHT11
#define GAS_SENSOR 0
#define LED_PIN 14
#define BUZZER_PIN 12

DHT dht(DHTPIN, DHTTYPE);
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
unsigned long gasDetectionTime = 0;
bool gasDetected = false;
void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  dht.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected");
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}
void loop()
{
  int gas = analogRead(GAS_SENSOR);
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.println("Gas: " + String(gas));
  Serial.println("Temp: " + String(temp));
  Serial.println("Humidity: " + String(hum));

  // Send sensor data to Firebase
  Firebase.RTDB.setInt(&fbdo, "/Sensor/Gas", gas);
  Firebase.RTDB.setFloat(&fbdo, "/Sensor/Temperature", temp);
  Firebase.RTDB.setFloat(&fbdo, "/Sensor/Humidity", hum);
  if (gas > 120)
  {
    if (!gasDetected)
    {
      // First detection of gas
      gasDetected = true;
      gasDetectionTime = millis();
      digitalWrite(LED_PIN, HIGH);  // Turn on LED immediately
      Firebase.RTDB.setString(&fbdo, "/Alert", "Gas Detected");
    }
    // Check 2 seconds 
    if (millis() - gasDetectionTime >= 2000) {
      digitalWrite(BUZZER_PIN, HIGH);  // Turn on buzzer after 2 seconds
    }
  } 
  else {
    if (gasDetected)
    { gasDetected = false;
      digitalWrite(LED_PIN, LOW);    // Turn off LED
      digitalWrite(BUZZER_PIN, LOW); // Turn off buzzer
      Firebase.RTDB.setString(&fbdo, "/Alert", "Safe");
    }
  }
  delay(1000);
}

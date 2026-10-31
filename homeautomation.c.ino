#define BLYNK_TEMPLATE_ID "TMPL31QB8DzQF"
#define BLYNK_TEMPLATE_NAME "HOME AUTOMATION"
#define BLYNK_AUTH_TOKEN "AsIUIq4hxyPcQq766WEPGUbVPA9f1Kee"


#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Enter your Wi-Fi credentials
char ssid[] ="sss";
char pass[] = "1234567890";

// Built-in LED on most NodeMCU ESP8266 boards
#define LED_PIN D1
#define LED2_PIN D2
#define FAN1 D5
#define FAN2 D6
// Blynk button on Virtual Pin V0
BLYNK_WRITE(V0)
{
  int state = param.asInt();

  // Built-in LED is active LOW
  digitalWrite(LED_PIN, state ? LOW : HIGH);

  Serial.println(state ? "LED ON" : "LED OFF");
}
BLYNK_WRITE(V1)
{
  int state = param.asInt();

  // Built-in LED is active LOW
  digitalWrite(LED2_PIN, state ? LOW : HIGH);

  Serial.println(state ? "LED ON" : "LED OFF");
}
BLYNK_WRITE(V2)
{
  int state = param.asInt();

  // Built-in LED is active LOW
  digitalWrite(FAN1, state ? LOW : HIGH);

  Serial.println(state ? "LED ON" : "LED OFF");
}
BLYNK_WRITE(V3)
{
  int state = param.asInt();

  // Built-in LED is active LOW
  digitalWrite(FAN2, state ? LOW : HIGH);

  Serial.println(state ? "LED ON" : "LED OFF");
}


void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
   pinMode(LED2_PIN, OUTPUT);
    pinMode(FAN1, OUTPUT);
     pinMode(FAN2, OUTPUT);
  //digitalWrite(LED_PIN, HIGH);  // LED initially OFF

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()1
{
  Blynk.run();
}
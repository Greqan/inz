#include <AndroidAccessory.h>
#define  LED_PIN  13
AndroidAccessory acc("Manufacturer",
    "Model",
    "Description",
    "1.0",
    "none",
    "none");
void setup()
{
  // set communiation speed
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  delay(1000);
  acc.powerOn();
}
 
void loop()
{
  byte msg[0];
  if (acc.isConnected()) {
    int len = acc.read(msg, sizeof(msg), 1);
    if (len > 0) {
      if (msg[0] == 0)
        digitalWrite(LED_PIN,HIGH);
      else
        digitalWrite(LED_PIN,LOW);
    }
  } 
  else
    digitalWrite(LED_PIN , LOW);
}

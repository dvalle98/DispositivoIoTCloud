#include <WiFiManager.h>
#include "arduino_secrets.h"


#include "thingProperties.h"


void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  bool res;
  res = wm.autoConnect("Sensores_IoT", "Sensores*");

  if (!res) {
    Serial.println("Failed to connect");
    delay(2000);
    ESP.restart();
  } else {
    Serial.println("connected...yeey :)");
  }
  Serial.print("Conectado con éxito, mi IP es: ");
  Serial.println(WiFi.localIP());


  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(/*ArduinoIoTPreferredConnection*/);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {

DispositivoCloud.calidad_aire = 100.0;
DispositivoCloud.humedad = 70;
DispositivoCloud.temperatura = 22.2;
DispositivoCloud.gases_presentes = false ;
DispositivoCloud.gases_toxicos = false ;


  ArduinoCloud.update();
  // Your code here

}






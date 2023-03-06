// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "7694edc6-3f5d-4780-b13a-99de35be0a5a";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

struct{
float calidad_aire;
float humedad;
float temperatura;
bool gases_presentes;
bool gases_toxicos;
} DispositivoCloud;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(DispositivoCloud.calidad_aire, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(DispositivoCloud.humedad, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(DispositivoCloud.temperatura, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(DispositivoCloud.gases_presentes, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(DispositivoCloud.gases_toxicos, READ, 5 * SECONDS, NULL);

}

//WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
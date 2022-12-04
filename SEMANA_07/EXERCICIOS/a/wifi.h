#include <WiFi.h>

//Variáveis
const char* ssid     = "exSemana7";
const char* password = "oitoletras";

//Inicialização do wifi do arduino
void wifiSetup(){
  WiFi.mode(WIFI_STA);
  WiFi.softAP(ssid, password); //Definição de nome e senha para o wifi

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
}
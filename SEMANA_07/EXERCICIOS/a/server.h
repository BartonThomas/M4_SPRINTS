#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

//Inicialização do servidor
AsyncWebServer server(80);

//Variáveis para guardar os inputs do html
const char* redPlay = "redGuess";
const char* greenPlay = "greenGuess";

//HTML para rodar no servidor WEB
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html><head>
  <title>Clicks</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script>
    function submitMessage() {
      alert("Valor salvo");
    }
  </script></head><body>

  <form action="/get" target="hidden-form">
    Jogador vermelho (insira um valor entre 0 e 20): <input type="number " name="redGuess">
    <input type="submit" value="Submit" onclick="submitMessage()">
  </form><br>

  <form action="/get" target="hidden-form">
    Jogador verde (insira um valor entre 0 e 20): <input type="number " name="greenGuess">
    <input type="submit" value="Submit" onclick="submitMessage()">
  </form><br>

  <iframe style="display:none" name="hidden-form"></iframe>
</body></html>)rawliteral";

//Função de leitura dos dados inputados
String readFile(fs::FS &fs, const char * path){
  File file = fs.open(path, "r");
  if(!file || file.isDirectory()){
    return String();
  }
  String fileContent;
  while(file.available()){
    fileContent+=String((char)file.read());
  }
  file.close();
  return fileContent;
}

//Função para reescrever os dados salvos
void writeFile(fs::FS &fs, const char * path, const char * message){
  File file = fs.open(path, "w");
  if(!file){
    return;
  }
  if(file.print(message)){
    Serial.println("- file written");
  } else {
    Serial.println("- write failed");
  }
  file.close();
}

//Função para mostrar os úlimos valores salvos
String processor(const String& var){
  if(var == "redGuess"){
    return readFile(SPIFFS, "/redGuess.txt");
  }

  else if(var == "greenGuess"){
    return readFile(SPIFFS, "/greenGuess.txt");
  }
  return String();
}

//Verificação por erros,,, setup do servidor
void serverSetup() {
  #ifdef ESP32
    if(!SPIFFS.begin(true)){
      return;
    }
  #else
    if(!SPIFFS.begin()){
      return;
    }
  #endif

  //Envio do html ao cliente
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  //API "GET" para pegar os valores salvos
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;

    if (request->hasParam(redPlay)) {
      inputMessage = request->getParam(redPlay)->value();
      writeFile(SPIFFS, "/redGuess.txt", inputMessage.c_str());
    }

    else if (request->hasParam(greenPlay)) {
      inputMessage = request->getParam(greenPlay)->value();
      writeFile(SPIFFS, "/greenGuess.txt", inputMessage.c_str());
    }

    else {
      inputMessage = "Erro no envio";
    }

    request->send(200, "text/text", inputMessage);
  });
  server.begin();
}

//Função utilizada para resetar os valores salvos e iniciar do zero
void resetFiles(String inputMessage){
  writeFile(SPIFFS, "/redGuess.txt", inputMessage.c_str());
  writeFile(SPIFFS, "/greenGuess.txt", inputMessage.c_str());
}
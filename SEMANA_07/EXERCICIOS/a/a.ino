#include "wifi.h"
#include "server.h"

int played = 0; //Variável usada para confirmação dos clicks dos jogadores
int number = rand() % 20; //Número aleatório entre 0 e 20 para o jogo

void setup(){
  Serial.begin(115200);
  wifiSetup(); //Função de setar o wifi
  serverSetup(); //Criação do html embarcado
  pinMode(13, OUTPUT); //LED verde
  pinMode(20, OUTPUT); //LED vermelho
  digitalWrite(13, LOW);
  digitalWrite(20, LOW);
  Serial.println(number);
}

//Variáveis para verificação da jogada de cada jogador
int rChange = 0;
int gChange = 0;

void loop(){
  //Variável dos jogadores
  int rPlayer = readFile(SPIFFS, "/redGuess.txt").toInt();
  int gPlayer = readFile(SPIFFS, "/greenGuess.txt").toInt();

  //Verificação para ver quantos jogadores já clicaram
  if(rPlayer < 10000  && rChange == 0){
    played += 1;
    rChange = 1;
  }
   if(gPlayer < 10000 && gChange == 0){
    played += 1;
    gChange = 1;
  }

  if(played == 2){
    resetFiles("100000"); //Função para remover as variáveis salvas

    //Reset das variáveis para continuar o jogo
    played = 0;
    rChange = 0;
    gChange = 0;

    int rScore = rPlayer-number;
    int gScore = gPlayer-number;

    //Verificação de que jogador chegou mais perto do valor real
    if(abs(rScore) == abs(gScore)){
      digitalWrite(13, HIGH);
      digitalWrite(20, HIGH);
      Serial.println("empate");
    }
    else if(abs(rScore) > abs(gScore)){
      digitalWrite(13, HIGH);
      digitalWrite(20, LOW);
      Serial.println("verde");
    }
    else if(abs(rScore) < abs(gScore)){
      digitalWrite(20, HIGH);
      digitalWrite(13, LOW);
      Serial.println("vermelho");
    }
    number = rand() % 20;
    Serial.println(number);
  }
  delay(1);
}
/*Arrays utilizadas para guardar a informação de todos os LEDs ascendidos e sons tocados*/
int music[50] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int leds[50] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int placement = 0;

void setup() {
  Serial.begin(9600);

  /*Setando pinos dos LEDs*/
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);

  /*Setando pinos do buzzer*/
  pinMode(7, OUTPUT);

  /*Setando pinos dos botões*/
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
}

void loop() {
  /*Variável utilizada para receber o código binário de outras funções*/
  int ldrBinary;

  /*Leitura dos botões de update e reset*/
  int buttonReset = digitalRead(20);
  int buttonUpdate = digitalRead(21);

  /*Verificação se o botão para fazer o update foi apertado*/
  if(buttonUpdate == LOW){
    ldrBinary = update();
    change(ldrBinary);
  }

  /*Verificação se o botão de reset foi apertado*/
  if(buttonReset == LOW){
    ldrBinary = 2222;
    change(ldrBinary);
    song();
  }
  delay(500); /*Delay de 0,5 segundos para não quebrar o esp32*/
}

int update() {
  const int place = placement; /*Constante utilizada para inserir novos valores de som na array msuic[] e leds[]*/
  int ldrRead = analogRead(14); /*Leitura dos dados recebidos pelo sensor*/
  ldrRead = map(ldrRead, 0, 4095, 0, 15); /*Mapeamento do número recebido para que fique entre 0 e 15*/
  int ldrReturn;
  /*Verificações do número lido pelo sensor convertido de 1 a 15, decisão de sons a serem tocados para cada combinação*/
  /*e conversão para um código binário dependendo do número*/
  switch(ldrRead){
    case 0:
    ldrReturn = 2222;
    noTone(7);
    break;
    case 1:
    ldrReturn = 1222;
    tone(7, 100);
    music[place] = 100;;
    leds[place] = ldrReturn;
    placement++;
    break;
    case 2:
    ldrReturn = 2122;
    tone(7, 200);
    music[place] = 200;;
    leds[place] = ldrReturn;
    placement++;
    break;
    case 3:
    ldrReturn = 2212;
    tone(7, 300);
    music[place] = 300;;
    leds[place] = ldrReturn;
    placement++;
    break;
    case 4:
    ldrReturn = 2221;
    tone(7, 400);
    music[place] = 400;;
    leds[place] = ldrReturn;
    placement++;
    break;
    case 5:
    ldrReturn = 1122;
    tone(7, 500);
    music[place] = 500;;
    leds[place] = ldrReturn;
    placement++;
    break;
    case 6:
    ldrReturn = 1212;
    tone(7, 600);
    music[place] = 600;;
    leds[place] = ldrReturn;
    placement++;
    break;
    case 7:
    ldrReturn = 1221;
    tone(7, 700);
    music[place] = 700;;
    leds[place] = ldrReturn;
    placement++;
    break;
    case 8:
    ldrReturn = 2112;
    tone(7, 800);
    music[place] = 800;;
    leds[place] = ldrReturn;
    placement++;
    break;
    case 9:
    ldrReturn = 2121;
    tone(7, 900);
    music[place] = 900;;
    leds[place] = ldrReturn;
    placement++;
    break;
    case 10:
    ldrReturn = 2211;
    tone(7, 1000);
    music[place] = 1000;
    leds[place] = ldrReturn;;
    placement++;
    break;
    case 11:
    ldrReturn = 1112;
    tone(7, 1100);
    music[place] = 1100;
    leds[place] = ldrReturn;;
    placement++;
    break;
    case 12:
    ldrReturn = 1121;
    tone(7, 1200);
    music[place] = 1200;
    leds[place] = ldrReturn;;
    placement++;
    break;
    case 13:
    ldrReturn = 1211;
    tone(7, 1300);
    music[place] = 1300;
    leds[place] = ldrReturn;;
    placement++;
    break;
    case 14:
    ldrReturn = 2111;
    tone(7, 1400);
    music[place] = 1400;
    leds[place] = ldrReturn;;
    placement++;
    break;
    case 15:
    ldrReturn = 1111;
    tone(7, 1500);
    music[place] = 1500;
    leds[place] = ldrReturn;;
    placement++;
    break;
  }
  return ldrReturn;
}

void change(int ldrBinary){
  /*Série de verificações do código binário para detectar quais LEDs ativar e desativar*/
  if(ldrBinary%10 == 1){
    digitalWrite(15, HIGH);
  }
  else{
    digitalWrite(15, LOW);
  }
  ldrBinary = (int)ldrBinary/10;

  if(ldrBinary%10 == 1){
    digitalWrite(16, HIGH);
  }
  else{
    digitalWrite(16, LOW);
  }
  ldrBinary = (int)ldrBinary/10;

  if(ldrBinary%10 == 1){
    ldrBinary -= 1;
    digitalWrite(17, HIGH);
  }
  else{
    digitalWrite(17, LOW);
  }
  ldrBinary = (int)ldrBinary/10;

  if(ldrBinary == 1){
    ldrBinary -= 1000;
    digitalWrite(18, HIGH);
  }
  else{
    digitalWrite(18, LOW);
  }
}

void song(){
  /*Inicia um loop para tocar todos os sons e acionar todos os leds previamente ativados*/
  for(int i = 0; i <= 50; i++){
    const int x = i;
    int z = music[x];
    int v = leds[x];
    change(v);
    tone(7, z);
    leds[x] = 0;
    music[x] = 0;
    delay(500);
    noTone(7);
    delay(500);
  }
}
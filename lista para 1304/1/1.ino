const int led1 = 8;
const int botaoA = 2;
const int botaoB = 3;

bool estadobotaoA = 1;
bool estadobotaoB = 1;  // valor certo do botao 2
bool ultimoestadoA = 1;
bool ultimoestadoB = 1;  // primeiro valor (sucetivel ao debounce)
unsigned long tempoA = 0;
unsigned long tempoB = 0;  //tempo para o segundo botao
const int debouncetimer = 50;


void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  valorA = digitalRead(botaoA);
  valorB = digitalRead(botaoB);

  if (valorA != ultimoestadoA)  // se o valor lido do botão for diferente do ultimo estado lido (primeiro)
  {
    tempoA = millis();  //guarda o mili segundo exato da mudança de estado do botao na variavel tempo
                        // atribiu a tempo o valor em mili segundos de quando o botão mudou de estado
  }

  if (millis() - tempoA > debouncetimer) {
    if (valorA != estadobotaoA) {
      estadobotaoA = valorA;
    }
  }

  if (valorB != ultimoestadoB) {
    tempoB = millis();
  }

  if (millis() - tempoB > debouncetimer) {
    if (valorB != estadobotaoB) {
      estadobotaoB = valorB;
    }
  }

ultimoestadoA = valorA;
ultimoestadoB = valorB;  

  if (ultimoestadoA == 0 && ultimoestadoB == 0) { // faz com o ultimo estado pq vai ser o valor limpo
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}
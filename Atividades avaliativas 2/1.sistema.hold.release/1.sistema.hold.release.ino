const int pot1 = A0;  //potenciometro 1 na porta analogica A0
const int pot2 = A1;  // potenciometro 2 na pora analogica A1

const int botaoA = 2;  // botao a u botao 1 na porta 2
const int botaoB = 3;  // botao b ou botao 2 na porta 3
const int led1 = 9;    // led 1 na porta 9
const int led2 = 10;   // led 2 na porta 10
const int led3 = 11;   // led 3 na porta 11
const int led4 = 12;   // led 4 na porta 12

bool estadobotaoA = 1;
bool estadobotaoB = 1;  // "valor certo" do botao 2
bool ultimoestadoA = 1;
bool ultimoestadoB = 1;        // primeiro valor (sucetivel ao debounce)
unsigned long tempoA = 0;      //tempo para o primeiro botao
unsigned long tempoB = 0;      //tempo para o segundo botao
const int debouncetimer = 50;  // define o tempo de espera para estabilização da leitura do botão

int valor = 0;      // variaveis de comparaçao
int valor_led = 0;  // variaveis de comparaçao


void setup() {
  pinMode(botaoA, INPUT_PULLUP);  // define se o botao vai ser pull up ou down intenamente
  pinMode(botaoB, INPUT_PULLUP);

  pinMode(pot1, INPUT);  // define potnciometro como entrada
  pinMode(pot2, INPUT);  // define potnciometro como entrada

  pinMode(led1, OUTPUT);  // define o led como saida
  pinMode(led2, OUTPUT);   // define o led como saida

  Serial.begin(115200);  // define velocidade
}

void loop() {
  valor = analogRead(pot1);      // valor passa a a ter o valor que o potenciometro manda
  valor_led = valor / 4;         // passa de 1023 pra 255 que é o fade do led
                                 // se 1023 é 2 na 10 e 255 2 na 8 então só fazer com base na diferença
                                 // deles que da 2 na 2 = 4
  analogWrite(led1, valor_led);  // coloca o valor de led como o valor lido

  int valorA = digitalRead(botaoA);
  int valorB = digitalRead(botaoB);

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

  if (botaoA == LOW) {  // se o botao a ou 1 estiver prssionado
    led1 == valor_led;  // n lembro como faz o efeito de cancelamento
    digitalWrite(led2, HIGH);
  }

  if (botaoB == LOW) {
    digitalWrite(led2, LOW);
  }
}

// fiz a base geral de tudo com os leds MAS n lembro coo fazer a função congelante.
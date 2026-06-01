const int botao1 = 2;
const int botao2 = 3;
bool estado_botao1 = 1;
bool estado_botao2 = 1;
bool ultimo_estado_botao1 = 1;   // high por conta do pullup interno
bool ultimo_estado_botao2 = 1;   // high por conta do pullup interno
unsigned long tempo_botao1 = 0;  // define como 0 o tempo qundo apertar o botão
                                 // pra começar a contar o debounce
unsigned long tempo_botao2 = 0;
unsigned long debounce = 50;
unsigned long tempo_anterior = 0;

int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;

void desligarleds() {       // cria a mesma função só que pra desligar
  digitalWrite(led1, LOW);  // o () siginifa que n recebe nenhum valor e só executa o que tem ali dentro dos {}
  digitalWrite(led2, LOW);  // os () vai ler o que ta ali e executar o que ta ali dentr
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void ligarleds1e2() {       
  digitalWrite(led1, HIGH);  
  digitalWrite(led2, HIGH);  
}

void ligarleds3e4() {       
  digitalWrite(led3, HIGH);  
  digitalWrite(led4, HIGH);  
}

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  int leitura_botao1 = digitalRead(botao1);
  int leitura_botao2 = digitalRead(botao2);

  if (leitura_botao1 != ultimo_estado_botao1) {
    tempo_botao1 = millis();
  }
  if ((millis() - tempo_botao1) > debounce) {
    if (leitura_botao1 != estado_botao1) {
      leitura_botao1 = estado_botao1;

      if (estado_botao1 == LOW) {
        unsigned long tempo_atual = millis();
        if (tempo_atual - tempo_anterior >= 300) {
          ligarleds1e2();
          tempo_anterior = tempo_atual;
          ligarleds3e4();
        }
      }
    }
  }

  if (leitura_botao2 != ultimo_estado_botao2) {
    tempo_botao2 = millis();
  }
  if ((millis() - tempo_botao2) > debounce) {
    if (leitura_botao2 != estado_botao2) {
      leitura_botao2 = estado_botao2;

      if (estado_botao2 == LOW) {
        desligarleds();
      }
    }
  }
}

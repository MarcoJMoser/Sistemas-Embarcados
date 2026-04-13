const int led1 = 8;

const int botaoA = 2; // inicia
const int botaoB = 3; // cancela

bool estadoA = HIGH;
bool estadoB = HIGH;

bool ultimoA = HIGH;
bool ultimoB = HIGH;

unsigned long tempoA = 0;
unsigned long tempoB = 0;

const int debounceDelay = 50;

// controle do temporizador
bool ledLigado = false;
unsigned long inicioTempo = 0;
const unsigned long duracao = 5000; // 5 segundos

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {

  // ===== LEITURA =====
  bool leituraA = digitalRead(botaoA);
  bool leituraB = digitalRead(botaoB);

  // ===== DEBOUNCE A =====
  if (leituraA != ultimoA) tempoA = millis();

  if ((millis() - tempoA) > debounceDelay) {
    if (leituraA != estadoA) {
      estadoA = leituraA;

      // clique no botão A → inicia temporizador
      if (estadoA == LOW) {
        ledLigado = true;
        inicioTempo = millis();
      }
    }
  }

  // ===== DEBOUNCE B =====
  if (leituraB != ultimoB) tempoB = millis();

  if ((millis() - tempoB) > debounceDelay) {
    if (leituraB != estadoB) {
      estadoB = leituraB;

      // clique no botão B → cancela
      if (estadoB == LOW) {
        ledLigado = false;
      }
    }
  }

  ultimoA = leituraA;
  ultimoB = leituraB;

  // ===== CONTROLE DO TEMPO =====
  if (ledLigado) {
    // verifica se passou 5 segundos
    if (millis() - inicioTempo >= duracao) {
      ledLigado = false;
    }
  }

  // ===== SAÍDA =====
  digitalWrite(led1, ledLigado);
}
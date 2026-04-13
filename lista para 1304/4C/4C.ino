const int led1 = 9;
const int botaoA = 2;

const int debounceDelay = 50;

bool estadoBotao = HIGH;
bool ultimaLeitura = HIGH;

unsigned long tempo = 0;

int nivel = 0;  // 0 a 4 (0%, 25%, 50%, 75%, 100%)

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {

  bool leitura = digitalRead(botaoA);

  // ===== DEBOUNCE =====
  if (leitura != ultimaLeitura) {
    tempo = millis();
  }

  if ((millis() - tempo) > debounceDelay) {
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      // Detecta clique (quando aperta)
      if (estadoBotao == LOW) {
        nivel++;

        if (nivel > 4) {
          nivel = 0;
        }
      }
    }
  }

  ultimaLeitura = leitura;

  // ===== CONTROLE DE BRILHO =====
  int brilho = 0;

  if (nivel == 0) brilho = 0;       // 0%
  if (nivel == 1) brilho = 64;      // 25%
  if (nivel == 2) brilho = 128;     // 50%
  if (nivel == 3) brilho = 191;     // 75%
  if (nivel == 4) brilho = 255;     // 100%

  analogWrite(led1, brilho);
}
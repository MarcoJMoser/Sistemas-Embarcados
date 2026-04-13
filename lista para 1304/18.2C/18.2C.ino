const int botao = 2;
const int atuador = 8; // LED

bool estadoBotao;
bool ultimoBotao = 1;

bool ativo = false;

unsigned long tempoInicio = 0;
const unsigned long tempoCiclo = 5000; // 5 segundos

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(atuador, OUTPUT);
}

void loop() {

  estadoBotao = digitalRead(botao);

  // ===== DETECTA CLIQUE =====
  if (estadoBotao == 0 && ultimoBotao == 1) {
    ativo = true;
    tempoInicio = millis(); // reinicia o ciclo
  }

  ultimoBotao = estadoBotao;

  // ===== CONTROLE DO TEMPO =====
  if (ativo) {

    digitalWrite(atuador, HIGH);

    if (millis() - tempoInicio >= tempoCiclo) {
      digitalWrite(atuador, LOW);
      ativo = false;
    }
  }
}
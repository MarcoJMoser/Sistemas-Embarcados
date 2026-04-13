const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

const int botao1 = 2; // inicia sequência
const int botao2 = 3; // reseta

bool estadoBotao1 = 1;
bool ultimoBotao1 = 1;

bool estadoBotao2 = 1;
bool ultimoBotao2 = 1;

unsigned long tempo = 0;
const int intervalo = 1000;

int etapa = 0;       // controla qual LED está ativo
bool sequenciaAtiva = false;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {

  estadoBotao1 = digitalRead(botao1);
  estadoBotao2 = digitalRead(botao2);

  // ===== BOTÃO 1 (INICIA) =====
  if (estadoBotao1 == 0 && ultimoBotao1 == 1) {
    sequenciaAtiva = true;
    etapa = 0;
    tempo = millis();
  }

  // ===== BOTÃO 2 (RESET) =====
  if (estadoBotao2 == 0 && ultimoBotao2 == 1) {
    sequenciaAtiva = false;
    etapa = 0;

    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  // ===== SEQUÊNCIA =====
  if (sequenciaAtiva) {
    if (millis() - tempo >= intervalo) {
      tempo = millis();
      etapa++;
    }

    if (etapa >= 1) digitalWrite(led1, HIGH);
    if (etapa >= 2) digitalWrite(led2, HIGH);
    if (etapa >= 3) digitalWrite(led3, HIGH);
    if (etapa >= 4) digitalWrite(led4, HIGH);

    // terminou sequência
    if (etapa >= 4) {
      sequenciaAtiva = false;
    }
  }

  ultimoBotao1 = estadoBotao1;
  ultimoBotao2 = estadoBotao2;
}
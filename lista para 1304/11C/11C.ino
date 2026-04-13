const int botaoA = 2;
const int led1 = 8; // curto
const int led2 = 9; // longo

bool estadoBotao = 1;
bool ultimoEstado = 1;

unsigned long tempoPressionado = 0;
unsigned long tempoSoltou = 0;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  estadoBotao = digitalRead(botaoA);

  // ===== DETECTA QUANDO APERTA =====
  if (estadoBotao == 0 && ultimoEstado == 1) {
    tempoPressionado = millis();
  }

  // ===== DETECTA QUANDO SOLTA =====
  if (estadoBotao == 1 && ultimoEstado == 0) {

    tempoSoltou = millis();
    unsigned long tempoTotal = tempoSoltou - tempoPressionado;

    Serial.print("Tempo pressionado: ");
    Serial.println(tempoTotal);

    // ===== DECISÃO =====
    if (tempoTotal < 1000) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }
    else if (tempoTotal > 2000) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
    }
    else {
      // entre 1s e 2s → nenhum
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
  }

  ultimoEstado = estadoBotao;
}
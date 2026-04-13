const int botaoA = 2;
const int botaoB = 3;

const int ledPrensa = 8; // LED 1
const int ledErro   = 11; // LED 4

bool estadoA = 1;
bool estadoB = 1;

bool ultimoA = 1;
bool ultimoB = 1;

unsigned long tempoA = 0;
unsigned long tempoB = 0;

const int limiteTempo = 500; // 500 ms

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);

  pinMode(ledPrensa, OUTPUT);
  pinMode(ledErro, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  estadoA = digitalRead(botaoA);
  estadoB = digitalRead(botaoB);

  // ===== DETECTA BORDA DE DESCIDA (APERTO) =====
  if (estadoA == 0 && ultimoA == 1) {
    tempoA = millis();
  }

  if (estadoB == 0 && ultimoB == 1) {
    tempoB = millis();
  }

  // ===== VERIFICA SE AMBOS ESTÃO PRESSIONADOS =====
  if (estadoA == 0 && estadoB == 0) {

    unsigned long diferenca = abs((long)(tempoA - tempoB));

    Serial.print("Dif: ");
    Serial.println(diferenca);

    if (diferenca <= limiteTempo) {
      // ✅ válido
      digitalWrite(ledPrensa, HIGH);
      digitalWrite(ledErro, LOW);
    } else {
      // ❌ inválido
      digitalWrite(ledPrensa, LOW);
      digitalWrite(ledErro, HIGH);
    }

  } else {
    // soltou algum botão → para tudo
    digitalWrite(ledPrensa, LOW);
  }

  ultimoA = estadoA;
  ultimoB = estadoB;
}
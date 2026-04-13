const int sensor = A0;

const int ledNormal = 8;
const int ledAlarme = 9;

int valor = 0;

// ===== LIMITE CRÍTICO =====
const int limite = 700;

// ===== CONTROLE DE PISCAR =====
unsigned long tempoAnterior = 0;
bool estadoPisca = false;

const int intervaloAlarme = 100; // 100 ms (rápido)

void setup() {
  pinMode(sensor, INPUT);

  pinMode(ledNormal, OUTPUT);
  pinMode(ledAlarme, OUTPUT);
}

void loop() {

  valor = analogRead(sensor);

  // ===== CONDIÇÃO CRÍTICA =====
  if (valor >= limite) {

    digitalWrite(ledNormal, LOW);

    // pisca rápido
    if (millis() - tempoAnterior >= intervaloAlarme) {
      tempoAnterior = millis();
      estadoPisca = !estadoPisca;
      digitalWrite(ledAlarme, estadoPisca);
    }

  } else {

    // estado normal
    digitalWrite(ledNormal, HIGH);
    digitalWrite(ledAlarme, LOW);
  }
}
const int sensor = A0;

const int valvula = 8;   // LED 1
const int alarme  = 9;   // LED 2 (ou 4, conforme teu enunciado)

int valor = 0;

// limites (0–1023)
const int nivel80 = 818;  // ~80%
const int nivel95 = 972;  // ~95%
const int nivel30 = 307;  // ~30%

bool valvulaLigada = true;

unsigned long tempoAnterior = 0;
const int intervalo = 200; // pisca rápido
bool estadoAlarme = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(valvula, OUTPUT);
  pinMode(alarme, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  valor = analogRead(sensor);

  Serial.print("Nivel: ");
  Serial.println(valor);

  // ===== CONTROLE DA VÁLVULA (com histerese) =====
  
  // fecha imediatamente se atingir 95%
  if (valor >= nivel95) {
    valvulaLigada = false;
  }

  // só reabre se cair abaixo de 30%
  if (valor <= nivel30) {
    valvulaLigada = true;
  }

  // ===== ACIONA VÁLVULA =====
  if (valvulaLigada && valor < nivel80) {
    digitalWrite(valvula, HIGH); // aberta
  } else {
    digitalWrite(valvula, LOW);  // fechada
  }

  // ===== ALARME DE TRANSBORDO =====
  if (valor >= nivel95) {

    if (millis() - tempoAnterior >= intervalo) {
      tempoAnterior = millis();
      estadoAlarme = !estadoAlarme;
      digitalWrite(alarme, estadoAlarme);
    }

  } else {
    digitalWrite(alarme, LOW);
  }

}
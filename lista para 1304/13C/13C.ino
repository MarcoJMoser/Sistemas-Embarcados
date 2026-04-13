const int potenciometro = A0;
const int led = 9;

unsigned int valor = 0;
float volts = 0;

unsigned long tempoAnterior = 0;
const int intervalo = 500; // pisca (500ms)
bool estadoLed = 0;

void setup() {
  pinMode(potenciometro, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  // ===== LEITURA =====
  valor = analogRead(potenciometro);
  volts = (valor * 5.0) / 1023;

  Serial.print("Volts: ");
  Serial.println(volts);

  // ===== ABAIXO DE 2V =====
  if (volts <= 2.0) {
    digitalWrite(led, LOW);
  }

  // ===== ENTRE 2V E 4V (PISCANDO) =====
  else if (volts > 2.0 && volts < 4.0) {

    if (millis() - tempoAnterior >= intervalo) {
      tempoAnterior = millis();
      estadoLed = !estadoLed;
      digitalWrite(led, estadoLed);
    }
  }

  // ===== ACIMA DE 4V =====
  else {
    digitalWrite(led, HIGH);
  }
}
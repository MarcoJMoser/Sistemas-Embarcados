const int potenciometro = A0;
const int led2 = 10;

unsigned int valorSensor = 0;

unsigned long tempoAnterior = 0;
unsigned long intervalo = 1000; // vai ser ajustado

bool estadoLed = LOW;

void setup() {
  pinMode(potenciometro, INPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  // ===== LEITURA DO POTENCIÔMETRO =====
  valorSensor = analogRead(potenciometro);

  // Converte 0–1023 → 2000ms a 100ms
  intervalo = 2000 - ((valorSensor * 1900UL) / 1023);

  Serial.print("Valor: ");
  Serial.print(valorSensor);
  Serial.print(" | Intervalo: ");
  Serial.println(intervalo);

  // ===== CONTROLE DE PISCADA =====
  if (millis() - tempoAnterior >= intervalo) {
    tempoAnterior = millis();

    estadoLed = !estadoLed;
    digitalWrite(led2, estadoLed);
  }

}
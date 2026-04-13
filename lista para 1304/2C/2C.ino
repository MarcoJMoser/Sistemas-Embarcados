const int leds[] = {2, 3, 4, 5};  // pinos dos 4 LEDs
const int qtdLeds = 4;

unsigned long tempoAnterior = 0;
const int intervalo = 200;

int ledAtual = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {

  if (millis() - tempoAnterior >= intervalo) {
    tempoAnterior = millis();

    // apaga todos os LEDs
    for (int i = 0; i < qtdLeds; i++) {
      digitalWrite(leds[i], LOW);
    }

    // liga o LED atual
    digitalWrite(leds[ledAtual], HIGH);

    // vai pro próximo LED
    ledAtual++;

    // volta pro início
    if (ledAtual >= qtdLeds) {
      ledAtual = 0;
    }
  }

}
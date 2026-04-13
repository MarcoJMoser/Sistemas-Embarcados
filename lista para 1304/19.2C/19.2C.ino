const int sensor = A0;

// LEDs (barra)
const int leds[] = {2, 3, 4, 5, 6};
const int numLeds = 5;

int valor = 0;
int nivel = 0;

// faixa do sensor (ajustável)
const int tempMin = 0;
const int tempMax = 1023;

void setup() {

  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(sensor, INPUT);
}

void loop() {

  valor = analogRead(sensor);

  // converte leitura para quantidade de LEDs
  nivel = map(valor, tempMin, tempMax, 0, numLeds);

  // garante limites
  if (nivel < 0) nivel = 0;
  if (nivel > numLeds) nivel = numLeds;

  // atualiza barra
  for (int i = 0; i < numLeds; i++) {

    if (i < nivel) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}
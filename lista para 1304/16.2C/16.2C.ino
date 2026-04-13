const int botaoMais  = 2;
const int botaoMenos = 3;

const int motor = 9; // LED PWM

int velocidade = 0; // 0 a 255

// ===== CONFIG =====
const int passo = 25; // incremento (~10%)
const int velMin = 0;
const int velMax = 255;

// ===== DEBOUNCE =====
bool estadoMais, ultimoMais = 1;
bool estadoMenos, ultimoMenos = 1;

unsigned long tempoMais = 0;
unsigned long tempoMenos = 0;

const unsigned long debounce = 50;

void setup() {
  pinMode(botaoMais, INPUT_PULLUP);
  pinMode(botaoMenos, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
}

void loop() {

  estadoMais = digitalRead(botaoMais);
  estadoMenos = digitalRead(botaoMenos);

  // ===== BOTÃO + =====
  if (estadoMais == 0 && ultimoMais == 1 && (millis() - tempoMais > debounce)) {
    velocidade += passo;
    tempoMais = millis();
  }

  // ===== BOTÃO - =====
  if (estadoMenos == 0 && ultimoMenos == 1 && (millis() - tempoMenos > debounce)) {
    velocidade -= passo;
    tempoMenos = millis();
  }

  ultimoMais = estadoMais;
  ultimoMenos = estadoMenos;

  // ===== LIMITAÇÃO (ANTI-ESTOURO) =====
  if (velocidade > velMax) velocidade = velMax;
  if (velocidade < velMin) velocidade = velMin;

  // ===== APLICA PWM =====
  analogWrite(motor, velocidade);
}
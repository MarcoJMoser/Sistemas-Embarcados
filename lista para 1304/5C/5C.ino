const int led1 = 8;

const int botao1 = 2; // comando
const int botao2 = 4; // bloqueio
const int botao3 = 3; // permissao

int valor1;
int valor2;
int valor3;

bool estado1 = HIGH;
bool estado2 = HIGH;
bool estado3 = HIGH;

bool ultimo1 = HIGH;
bool ultimo2 = HIGH;
bool ultimo3 = HIGH;

unsigned long tempo1 = 0;
unsigned long tempo2 = 0;
unsigned long tempo3 = 0;

const int debounceDelay = 50;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {

  // ===== LEITURA =====
  valor1 = digitalRead(botao1);
  valor2 = digitalRead(botao2);
  valor3 = digitalRead(botao3);

  // ===== DEBOUNCE 1 =====
  if (valor1 != ultimo1) tempo1 = millis();
  if (millis() - tempo1 > debounceDelay) {
    if (valor1 != estado1) estado1 = valor1;
  }

  // ===== DEBOUNCE 2 =====
  if (valor2 != ultimo2) tempo2 = millis();
  if (millis() - tempo2 > debounceDelay) {
    if (valor2 != estado2) estado2 = valor2;
  }

  // ===== DEBOUNCE 3 =====
  if (valor3 != ultimo3) tempo3 = millis();
  if (millis() - tempo3 > debounceDelay) {
    if (valor3 != estado3) estado3 = valor3;
  }

  ultimo1 = valor1;
  ultimo2 = valor2;
  ultimo3 = valor3;

  // ===== LÓGICA FINAL =====
  if (estado1 == LOW && estado3 == LOW && estado2 == HIGH) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}
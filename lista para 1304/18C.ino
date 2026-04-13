const int potenciometro = A0;

const int motor = 9;   // LED 1 (PWM)
const int ledFalha = 8; // LED 2

const int botaoA = 2; // emergência

bool estadoBotao = 1;
bool ultimoBotao = 1;

bool emergencia = false;

int valor = 0;
int pwm = 0;

unsigned long tempoAnterior = 0;
const int intervalo = 300; // pisca do erro
bool estadoLed = 0;

void setup() {
  pinMode(potenciometro, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(ledFalha, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {

  estadoBotao = digitalRead(botaoA);

  // ===== DETECTA EMERGÊNCIA =====
  if (estadoBotao == 0 && ultimoBotao == 1) {
    emergencia = true; // trava em falha
  }

  ultimoBotao = estadoBotao;

  // ===== SE ESTIVER EM EMERGÊNCIA =====
  if (emergencia) {

    analogWrite(motor, 0); // para motor

    // LED piscando (falha crítica)
    if (millis() - tempoAnterior >= intervalo) {
      tempoAnterior = millis();
      estadoLed = !estadoLed;
      digitalWrite(ledFalha, estadoLed);
    }

  } else {

    // funcionamento normal
    valor = analogRead(potenciometro);
    pwm = valor / 4; // 0–1023 → 0–255

    analogWrite(motor, pwm);
    digitalWrite(ledFalha, LOW);
  }

}
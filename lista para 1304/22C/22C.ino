const int ldr = A0;
const int led = 9; // PWM

const int botaoA = 2; // presença

int valorLuz = 0;
int pwm = 0;

bool estadoBotao = 1;

void setup() {
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {

  estadoBotao = digitalRead(botaoA);
  valorLuz = analogRead(ldr);

  Serial.print("LDR: ");
  Serial.println(valorLuz);

  // ===== SEM PRESENÇA =====
  if (estadoBotao == 1) {
    pwm = 25; // ~10% de 255
  }

  // ===== COM PRESENÇA =====
  else {

    // inversão: mais luz ambiente → menos LED
    pwm = map(valorLuz, 0, 1023, 255, 0);

    // limite mínimo pra não apagar totalmente (opcional)
    if (pwm < 20) pwm = 20;
  }

  analogWrite(led, pwm);
}
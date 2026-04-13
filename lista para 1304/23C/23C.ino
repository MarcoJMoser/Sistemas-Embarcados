const int botaoA = 2;

const int led1 = 8;  // pressão
const int led2 = 9;  // corrente (PWM)
const int led3 = 10; // pronto

const int potenciometro = A0;

bool estadoBotao = 1;
bool ultimoBotao = 1;

bool rodando = false;

int etapa = 0;
unsigned long tempoInicio = 0;

int pwm = 0;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(potenciometro, INPUT);
}

void loop() {

  estadoBotao = digitalRead(botaoA);

  // ===== INICIA CICLO =====
  if (estadoBotao == 0 && ultimoBotao == 1 && !rodando) {
    rodando = true;
    etapa = 1;
    tempoInicio = millis();
  }

  ultimoBotao = estadoBotao;

  if (rodando) {

    // ===== ETAPA 1 – ESPERA 800ms =====
    if (etapa == 1) {

      if (millis() - tempoInicio >= 800) {
        etapa = 2;
        tempoInicio = millis();
      }
    }

    // ===== ETAPA 2 – PRESSÃO =====
    else if (etapa == 2) {

      digitalWrite(led1, HIGH);

      if (millis() - tempoInicio >= 200) {
        etapa = 3;
        tempoInicio = millis();
      }
    }

    // ===== ETAPA 3 – SOLDA (PWM 1,5s) =====
    else if (etapa == 3) {

      int valor = analogRead(potenciometro);
      pwm = valor / 4;

      analogWrite(led2, pwm);

      if (millis() - tempoInicio >= 1500) {
        analogWrite(led2, 0);
        etapa = 4;
        tempoInicio = millis();
      }
    }

    // ===== ETAPA 4 – RESFRIAMENTO =====
    else if (etapa == 4) {

      digitalWrite(led1, HIGH);

      if (millis() - tempoInicio >= 500) {
        digitalWrite(led1, LOW);
        etapa = 5;
        tempoInicio = millis();
      }
    }

    // ===== ETAPA 5 – PRONTO =====
    else if (etapa == 5) {

      digitalWrite(led3, HIGH);

      if (millis() - tempoInicio >= 2000) {
        digitalWrite(led3, LOW);
        rodando = false;
        etapa = 0;
      }
    }
  }
}
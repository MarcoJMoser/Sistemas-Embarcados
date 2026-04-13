const int botaoA = 2;

const int led1 = 8;  // enchimento
const int led2 = 9;  // lavagem (PWM)
const int led3 = 10; // lavagem (PWM)
const int led4 = 11; // drenagem

bool estadoBotao = 1;
bool ultimoBotao = 1;

bool rodando = false;

int etapa = 0;

unsigned long tempoInicio = 0;
unsigned long tempoPisca = 0;

bool alterna = false;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
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

    // ===== ETAPA 1 – ENCHIMENTO (4s) =====
    if (etapa == 1) {

      digitalWrite(led1, HIGH);

      if (millis() - tempoInicio >= 4000) {
        digitalWrite(led1, LOW);
        etapa = 2;
        tempoInicio = millis();
      }
    }

    // ===== ETAPA 2 – LAVAGEM (8s) =====
    else if (etapa == 2) {

      // alternância PWM
      if (millis() - tempoPisca >= 500) {
        tempoPisca = millis();
        alterna = !alterna;
      }

      if (alterna) {
        analogWrite(led2, 127); // 50%
        analogWrite(led3, 0);
      } else {
        analogWrite(led2, 0);
        analogWrite(led3, 127); // 50%
      }

      if (millis() - tempoInicio >= 8000) {
        analogWrite(led2, 0);
        analogWrite(led3, 0);
        etapa = 3;
        tempoInicio = millis();
      }
    }

    // ===== ETAPA 3 – DRENAGEM (4s) =====
    else if (etapa == 3) {

      digitalWrite(led4, HIGH);

      if (millis() - tempoInicio >= 4000) {
        digitalWrite(led4, LOW);
        rodando = false; // fim do ciclo
        etapa = 0;
      }
    }
  }
}
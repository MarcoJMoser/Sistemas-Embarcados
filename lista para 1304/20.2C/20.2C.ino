const int nivelSensor = A0;
const int tempSensor  = A1;
const int botao       = 2;

// saídas
const int valvula   = 8;  // LED1
const int aquecedor = 9;  // LED2 (PWM)
const int alarme    = 10; // LED3

// ===== LIMITES =====
const int nivelBaixo = 300;
const int nivelAlto  = 700;

const int tempBaixa = 300;
const int tempAlta  = 700;

// ===== CONTROLE DE ALARME =====
unsigned long tempoAnterior = 0;
bool estadoPisca = false;

void setup() {
  pinMode(botao, INPUT_PULLUP);

  pinMode(valvula, OUTPUT);
  pinMode(aquecedor, OUTPUT);
  pinMode(alarme, OUTPUT);
}

void loop() {

  // ===== HABILITAÇÃO =====
  if (digitalRead(botao) == HIGH) {
    // sistema desligado
    digitalWrite(valvula, LOW);
    analogWrite(aquecedor, 0);
    digitalWrite(alarme, LOW);
    return;
  }

  // ===== LEITURAS =====
  int nivel = analogRead(nivelSensor);
  int temp  = analogRead(tempSensor);

  // ===== CONTROLE DE NÍVEL =====
  if (nivel <= nivelBaixo) {
    digitalWrite(valvula, HIGH); // abre
  }
  else if (nivel >= nivelAlto) {
    digitalWrite(valvula, LOW);  // fecha
  }

  // ===== CONTROLE DE TEMPERATURA =====
  if (temp <= tempBaixa) {
    analogWrite(aquecedor, 255); // liga forte
  }
  else if (temp >= tempAlta) {
    analogWrite(aquecedor, 0);   // desliga
  }

  // ===== ALARME DE TEMPERATURA ALTA =====
  if (temp >= tempAlta) {

    if (millis() - tempoAnterior >= 200) {
      tempoAnterior = millis();
      estadoPisca = !estadoPisca;
      digitalWrite(alarme, estadoPisca);
    }

  } else {
    digitalWrite(alarme, LOW);
  }
}
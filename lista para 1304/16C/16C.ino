const int sensor = A0;

const int exaustor = 9; // LED 2 (PWM)
const int ledMax   = 8; // LED 1

int valor = 0;
float temperatura = 0;

int pwm = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(exaustor, OUTPUT);
  pinMode(ledMax, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  // ===== LEITURA =====
  valor = analogRead(sensor);

  // ⚠️ ajuste simples (simulação Tinkercad)
  temperatura = map(valor, 0, 1023, 0, 100);

  Serial.print("Temp: ");
  Serial.println(temperatura);

  // ===== ABAIXO DE 30°C =====
  if (temperatura < 30) {
    pwm = 51; // 20% de 255
    digitalWrite(ledMax, LOW);
  }

  // ===== ENTRE 30°C E 60°C =====
  else if (temperatura >= 30 && temperatura <= 60) {
    pwm = map(temperatura, 30, 60, 51, 255);
    digitalWrite(ledMax, LOW);
  }

  // ===== ACIMA DE 60°C =====
  else {
    pwm = 255; // 100%
    digitalWrite(ledMax, HIGH);
  }

  // ===== APLICA PWM =====
  analogWrite(exaustor, pwm);
}
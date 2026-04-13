const int potenciometro = A0;

const int led1 = 9;
const int led2 = 10;
const int led3 = 11;
const int led4 = 12;

unsigned int valor_sensor = 0;
float porcentagem = 0;

void setup() {
  pinMode(potenciometro, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  valor_sensor = analogRead(potenciometro);

  // converte pra porcentagem (0 a 100%)
  porcentagem = (valor_sensor * 100.0) / 1023.0;

  Serial.print("Valor = ");
  Serial.print(valor_sensor);
  Serial.print(" | % = ");
  Serial.println(porcentagem);

  // ===== BARGRAPH =====

  if (porcentagem < 25) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  else if (porcentagem < 50) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  else if (porcentagem < 75) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }

  else if (porcentagem < 90) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }

  else {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}
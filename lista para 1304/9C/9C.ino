const int potenciometro = A0;
const int led3 = 11;

unsigned int valor = 0;
unsigned long soma = 0;
unsigned int media = 0;

void setup() {
  pinMode(potenciometro, INPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  soma = 0;

  // ===== LE 10 VEZES =====
  for (int i = 0; i < 10; i++) {
    valor = analogRead(potenciometro);
    soma += valor;
    delay(10); // pequeno intervalo
  }

  // ===== CALCULA MÉDIA =====
  media = soma / 10;

  Serial.print("Media: ");
  Serial.println(media);

  // ===== DECISÃO =====
  if (media > 700) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }

}
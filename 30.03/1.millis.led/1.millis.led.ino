const int led_verde = 8;
const int led_amarelo = 9;
const int led_vermelho = 10;
const int led_branco = 11;
bool estado = 0;
unsigned long tempo_anterior = 0;

void setup() {
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_branco, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long tempo_atual = millis();
  if (tempo_atual - tempo_anterior >= 1000) {
    estado = !estado;
    digitalWrite(led_verde, estado);
    digitalWrite(led_amarelo, estado);
    digitalWrite(led_vermelho, estado);
    digitalWrite(led_branco, estado);
    tempo_anterior = tempo_atual;
    Serial.println("1 segundo");
  }
}

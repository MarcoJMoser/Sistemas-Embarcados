const int potenciometro = A0;

const int ledVerde   = 8;  // normal
const int ledAmarelo = 9;  // baixa tensão
const int ledVermelho = 10; // alta tensão
const int chaveGeral = 11; // LED 4

int valor = 0;
float tensao = 0;

unsigned long tempoFalha = 0;
bool foraLimite = false;
bool sistemaAtivo = true;

void setup() {
  pinMode(potenciometro, INPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(chaveGeral, OUTPUT);

  Serial.begin(115200);
}

void loop() {

  valor = analogRead(potenciometro);

  // 0–1023 → 0–250V
  tensao = (valor * 250.0) / 1023;

  Serial.print("Tensao: ");
  Serial.println(tensao);

  // ===== INDICADORES =====
  if (tensao >= 210 && tensao <= 230) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  else if (tensao < 210) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  }
  else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  // ===== FAIXA CRÍTICA =====
  if (tensao < 180 || tensao > 240) {

    if (!foraLimite) {
      foraLimite = true;
      tempoFalha = millis();
    }

    // passou 2 segundos fora → desliga sistema
    if (millis() - tempoFalha >= 2000) {
      sistemaAtivo = false;
    }

  } else {
    foraLimite = false;
  }

  // ===== CHAVE GERAL =====
  if (sistemaAtivo) {
    digitalWrite(chaveGeral, HIGH);
  } else {
    digitalWrite(chaveGeral, LOW);
  }

}
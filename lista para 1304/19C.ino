const int botaoA = 2;
const int sensor = A0;

const int resistencia = 8; // LED 1
const int ledFaixa    = 9; // LED 2

bool estadoBotao = 1;
bool ultimoBotao = 1;

bool sistemaLigado = false;
bool aquecendo = false;

int valor = 0;

// limites simulados
const int temp150 = 614; // ~150°C
const int temp160 = 655; // ~160°C

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(sensor, INPUT);
  pinMode(resistencia, OUTPUT);
  pinMode(ledFaixa, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  estadoBotao = digitalRead(botaoA);

  // ===== LIGA SISTEMA =====
  if (estadoBotao == 0 && ultimoBotao == 1) {
    sistemaLigado = true;
    aquecendo = true;
  }

  ultimoBotao = estadoBotao;

  valor = analogRead(sensor);

  Serial.print("Temp (valor): ");
  Serial.println(valor);

  if (sistemaLigado) {

    // ===== HISTERESE =====

    // desliga aquecimento em 160
    if (valor >= temp160) {
      aquecendo = false;
    }

    // só religa quando cair pra 150
    if (valor <= temp150) {
      aquecendo = true;
    }

    // ===== CONTROLE DA RESISTÊNCIA =====
    if (aquecendo) {
      digitalWrite(resistencia, HIGH);
    } else {
      digitalWrite(resistencia, LOW);
    }

    // ===== LED FAIXA (150 a 160) =====
    if (valor >= temp150 && valor <= temp160) {
      digitalWrite(ledFaixa, HIGH);
    } else {
      digitalWrite(ledFaixa, LOW);
    }

  } else {
    digitalWrite(resistencia, LOW);
    digitalWrite(ledFaixa, LOW);
  }

}
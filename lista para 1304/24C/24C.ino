const int sensor = A0;
const int aquecedor = 8; // LED

int valor = 0;

// ===== LIMITES (AJUSTÁVEIS) =====
const int limiteInferior = 400; // liga
const int limiteSuperior = 600; // desliga

bool aquecendo = false;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(aquecedor, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  valor = analogRead(sensor);

  Serial.print("Leitura: ");
  Serial.println(valor);

  // ===== HISTERESE =====

  // liga só quando estiver abaixo do limite inferior
  if (valor <= limiteInferior) {
    aquecendo = true;
  }

  // desliga só quando passar do limite superior
  if (valor >= limiteSuperior) {
    aquecendo = false;
  }

  // ===== APLICA SAÍDA =====
  if (aquecendo) {
    digitalWrite(aquecedor, HIGH);
  } else {
    digitalWrite(aquecedor, LOW);
  }
}
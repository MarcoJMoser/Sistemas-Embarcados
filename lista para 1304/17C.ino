const int botaoA = 2; // start/reset (sensor presença)
const int botaoB = 3; // contador de caixas

const int esteira = 8; // LED 1

bool estadoA = 1;
bool estadoB = 1;

bool ultimoA = 1;
bool ultimoB = 1;

int contadorCaixas = 0;
int contadorLote = 0;

bool rodando = false;
bool pausado = false;

unsigned long tempoPausa = 0;
const int tempoParada = 3000; // 3s

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(esteira, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  estadoA = digitalRead(botaoA);
  estadoB = digitalRead(botaoB);

  // ===== BOTÃO A (START / RESET) =====
  if (estadoA == 0 && ultimoA == 1) {

    if (contadorCaixas >= 20) {
      // reset total
      contadorCaixas = 0;
      contadorLote = 0;
      rodando = true;
    } else {
      // start normal
      rodando = true;
    }
  }

  // ===== CONTAGEM DE CAIXAS (BOTÃO B) =====
  if (estadoB == 0 && ultimoB == 1 && rodando && !pausado) {
    contadorCaixas++;
    contadorLote++;

    Serial.print("Total: ");
    Serial.println(contadorCaixas);
  }

  // ===== A CADA 5 CAIXAS → PAUSA =====
  if (contadorLote == 5) {
    pausado = true;
    tempoPausa = millis();
    contadorLote = 0;
  }

  // ===== CONTROLE DA PAUSA =====
  if (pausado) {
    digitalWrite(esteira, LOW);

    if (millis() - tempoPausa >= tempoParada) {
      pausado = false;
    }
  }

  // ===== PARA TOTAL EM 20 CAIXAS =====
  if (contadorCaixas >= 20) {
    rodando = false;
    digitalWrite(esteira, LOW);
  }

  // ===== ESTEIRA LIGADA =====
  if (rodando && !pausado) {
    digitalWrite(esteira, HIGH);
  }

  ultimoA = estadoA;
  ultimoB = estadoB;
}
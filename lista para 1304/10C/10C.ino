const int potenciometro = A0;

const int led1 = 9;  // lado "negativo"
const int led2 = 10; // lado "positivo"

int valor = 0;
int brilho1 = 0;
int brilho2 = 0;

void setup() {
  pinMode(potenciometro, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  valor = analogRead(potenciometro);

  Serial.print("Valor: ");
  Serial.println(valor);

  // ===== REGIÃO CENTRAL =====
  if (valor == 512) {
    brilho1 = 0;
    brilho2 = 0;
  }

  // ===== ABAIXO DO CENTRO =====
  else if (valor < 512) {
    brilho1 = map(valor, 512, 0, 0, 255); // quanto menor, mais brilho
    brilho2 = 0;
  }

  // ===== ACIMA DO CENTRO =====
  else {
    brilho2 = map(valor, 512, 1023, 0, 255); // quanto maior, mais brilho
    brilho1 = 0;
  }

  analogWrite(led1, brilho1);
  analogWrite(led2, brilho2);
}
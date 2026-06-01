/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Sistema de ventilação

Autor: Marco J. Moser C
Data: 20/04/2026
Versão: 1.0

************************************************************************ */
const int pot1 = A0;  //potenciometro 1 na porta analogica A0

const int led1 = 9;   // led 1 na porta 9
const int led2 = 10;  // led 2 na porta 10

int valor = 0;      // variaveis de comparaçao
int valor_led = 0;  // variaveis de comparaçao
int valor_temperatura = 0;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(pot1, INPUT);
  Serial.begin(115200);
}

void loop() {
  valor = analogRead(pot1);                     // valor passa a a ter o valor que o potenciometro manda
  valor_temperatura = (valor * 100.00) / 1026;  // converte pra porcentagem (0 a 100%)

  Serial.print("temperatura dos gases:");
  Serial.println(valor_temperatura);

  if (valor_temperatura < 30) {
    valor_led = 51;
    analogWrite(led1, valor_led);
    digitalWrite(led2, LOW);
  }

  else if (valor_temperatura > 30 && 60 >= valor_temperatura) {
    valor_led = valor/4;  // passa de 1023 pra 255 que é o fade do led
    analogWrite(led1, valor_led);
    digitalWrite(led2, LOW);
  }
 
  if (valor_temperatura > 60) {
    valor_led = 255;
    analogWrite(led1, valor_led);
    digitalWrite(led2, HIGH);
    Serial.println("Capacidade máxima atingida!");
  }
}

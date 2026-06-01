const int ledPin = 9;  // led no pino 9
const int potenciometro = 14;     //  define o potenciometro no pino 14
int valor = 0; // variaveis de comparaçao
int valor_led = 0;

void setup() {
  digitalWrite(potenciometro, INPUT); // coloca o potenciometro como entrada
  Serial.begin(115200);
}

void loop() {
  valor = analogRead(potenciometro); // valor passa a a ter o valor que o potenciometro manda
  valor_led = valor/4;               // passa de 1023 pra 255 que é o fade do led 
                                     // se 1023 é 2 na 10 e 255 2 na 8 então só fazer com base na diferença 
                                     // deles que da 2 na 2 = 4 
  analogWrite(ledPin, valor_led);    // coloca o valor de led como o valor lido 
  Serial.println(valor);             // coloca na serial 
  Serial.println(valor_led);
}
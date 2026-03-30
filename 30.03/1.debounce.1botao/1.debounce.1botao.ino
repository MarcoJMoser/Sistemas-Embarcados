const int botao = 2;
const int led = 8;
int estado_led = LOW;
int estado_botao;                // variavek pra comparação e fazer o tempo do debounce
int ultimo_estado_botao = HIGH;  // primiero valor do botao (que vai ser high pq ele tem pullupp interno)
unsigned long tempo_debounce = 0;
unsigned long atraso = 50;


void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, estado_led);  // mesma coisa que colocar como low
}

void loop() {
  int leitura = digitalRead(botao);      // a variavel leitura vai guardar o valor lido pelo botao
  if (leitura != ultimo_estado_botao) {  // se o valor de leitura for diferente do ultimo estado do botao (no caso high)
                                        // a variavel tempo_debounce vai guardar
    tempo_debounce = millis();
  }

  if ((millis() - tempo_debounce) > atraso) {  //se der maior que os 50 ms do debounce executa o que ta dentro do if
    if (leitura != estado_botao) {
      estado_botao = leitura;
      if (estado_botao == LOW) {
        estado_led = !estado_led;  // mesma coisa que ligar por digita write (acho eu )
      }
    }
  }
  digitalWrite(led, estado_led); // vai salvar o valor do botão como low pra proxima vez que for apertar ele desligar o led
  ultimo_estado_botao = leitura; 
}

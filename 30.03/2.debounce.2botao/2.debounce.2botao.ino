const int botao1 = 2;
const int botao2 = 3;
const int led = 8;
int estado_led = LOW;
int estado_botao1;                // variavek pra comparação e fazer o tempo do debounce
int estado_botao2;
int ultimo_estado_botao1 = HIGH;  // primiero valor do botao (que vai ser high pq ele tem pullupp interno)
int ultimo_estado_botao2 = HIGH;
unsigned long tempo_debounce1 = 0;
unsigned long tempo_debounce2 = 0;
unsigned long atraso = 50;


void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, estado_led);  // mesma coisa que colocar como low
}

void loop() {
  int leitura1 = digitalRead(botao1);      // a variavel leitura vai guardar o valor lido pelo botao
  int leitura2 = digitalRead(botao2); 
  
  if (leitura1 != ultimo_estado_botao1) {  // se o valor de leitura for diferente do ultimo estado do botao (no caso high)
                                        // a variavel tempo_debounce vai guardar
    tempo_debounce1 = millis();
  }

  if ((millis() - tempo_debounce1) > atraso) {  //se der maior que os 50 ms do debounce executa o que ta dentro do if
    if (leitura1 != estado_botao1) {
      estado_botao1 = leitura1;
      if (estado_botao1 == LOW) {
        estado_led = !estado_led;  // mesma coisa que ligar por digita write (acho eu )
      }
    }
  }

  if (leitura2 != ultimo_estado_botao2) {  // se o valor de leitura for diferente do ultimo estado do botao (no caso high)
                                        // a variavel tempo_debounce vai guardar
    tempo_debounce2 = millis();
  }

  if ((millis() - tempo_debounce2) > atraso) {  //se der maior que os 50 ms do debounce executa o que ta dentro do if
    if (leitura2 != estado_botao2) {
      estado_botao2 = leitura2;
      if (estado_botao2 == LOW) {
        estado_led = !estado_led;  // mesma coisa que ligar por digita write (acho eu )
      }
    }
  }
  digitalWrite(led, estado_led); // vai salvar o valor do botão como low pra proxima vez que for apertar ele desligar o led
  ultimo_estado_botao1 = leitura1; 
  ultimo_estado_botao2 = leitura2; 
}

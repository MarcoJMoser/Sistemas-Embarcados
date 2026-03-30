const int botao1 = 2;
const int botao2 = 3; // botao que desliga 
const int led = 8;
int estado_led = LOW;
bool estado_botao1;    
bool estado_botao2;           
int ultimo_estado_botao = HIGH;
int ultimo_estado_botao2 = HIGH;
unsigned long tempo_debounce1 = 0;
unsigned long tempo_debounce2 = 0;
unsigned long atraso = 50;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  digitalWrite(led, estado_led);  
}

void loop() {
  int leitura1 = digitalRead(botao1);
  int leitura2 = digitalRead(botao2);

  if (leitura1 != ultimo_estado_botao) { 
    tempo_debounce1 = millis();
  }

  if ((millis() - tempo_debounce1) > atraso) {  
    if (leitura1 != estado_botao1) {
      estado_botao1 = leitura1;
    }
      if (estado_botao1 == LOW) {
        estado_led = 1;  
    }
  }
  if (leitura2 != ultimo_estado_botao2) { 
    tempo_debounce2 = millis();
  }

  if ((millis() - tempo_debounce2) > atraso) {  
    if (leitura2 != estado_botao2) {
      estado_botao2 = leitura2;
    }
      if (estado_botao2 == LOW) {
        estado_led = 0;  
    }
  }
  digitalWrite(led, estado_led); // vai salvar o valor do botão como low pra proxima vez que for apertar ele desligar o led
  ultimo_estado_botao = leitura1; 
  ultimo_estado_botao2 = leitura2;
}
// um botao liga e o outro deliga 
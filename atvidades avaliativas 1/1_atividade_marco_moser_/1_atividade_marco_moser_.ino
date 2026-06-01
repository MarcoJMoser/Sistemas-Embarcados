// o botao 1 incrementa o valor do contador (0 a 15) e o botão 2 descrementa 
// a cada alteração, os leds motram o valor atual em binário
// o sistema deve impedir que o valor ultrapasse os limites (n deve ir abaixo de 0 nem acima de 15)

const int botao_incremento = 2;
const int botao_decremento = 3;
bool estado_botao1 = 1;
bool estado_botao2 = 1;
bool ultimo_estado_botao1 = 1; // high por conta do pullup interno
bool ultimo_estado_botao2 = 1;  // high por conta do pullup interno
unsigned long tempo_botao1 = 0; // define como 0 o tempo qundo apertar o botão 
                                // pra começar a contar o debounce
unsigned long tempo_botao2 = 0;
unsigned long debounce = 50;
int contador = 0; // cria ua variavel pro contador 
                // que vai ser em numeros binários 
                // coloca como bool pq dai pega logica boleana ? (dai se incrementa fica na lógica binária ????) (to chutando)
int led_verde = 8;
int led_amarelo = 9;
int led_vermelho = 10;               


void setup() {
  pinMode(botao_incremento, INPUT_PULLUP);
  pinMode(botao_decremento, INPUT_PULLUP);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
}

void loop() {
  int leitura_botao1 = digitalRead(estado_botao1);
  int leitura_botao2 = digitalRead(estado_botao2);

  if (leitura_botao1 != ultimo_estado_botao1){
    tempo_botao1 = millis();
  }
  if ((millis() - tempo_botao1) > debounce){
    if (leitura_botao1 != estado_botao1){
      leitura_botao1 = estado_botao1;
      
      if (estado_botao1 == LOW){
        contador++;
        Serial.print("contagem: ");  //Imostra no serial a contagem
        Serial.println(contador); //mostra na serial o valor contado
        switch (contador){
          case '1':
          digitalWrite(led_verde, HIGH);
          break;

          case'10':
          digitalWrite(led_verde, HIGH);
          digitalWrite(led_amarelo, HIGH);
          break;

          case '11':
          digitalWrite(led_verde, HIGH);
          digitalWrite(led_amarelo, HIGH);
          digitalWrite(led_vermelho, HIGH);
          break;

          default:
          
        }
      }
    }
  }

  if (leitura_botao2 != ultimo_estado_botao2){
    tempo_botao2 = millis();
  }
  if ((millis() - tempo_botao2) > debounce){
    if (leitura_botao2 != estado_botao2){
      leitura_botao2 = estado_botao2;
      
      if (estado_botao2 == LOW){
        contador--;
        Serial.print("contagem: ");  //Imostra no serial a contagem
        Serial.println(contador); //mostra na serial o valor contado
        switch (contador){
          case '1':
          digitalWrite(led_verde, HIGH);
          digitalWrite(led_amarelo, LOW);
          digitalWrite(led_vermelho, LOW);
          break;

          case'10':
          digitalWrite(led_verde, HIGH);
          digitalWrite(led_amarelo, HIGH);
          digitalWrite(led_vermelho, LOW);
          break;

          case '11':
          digitalWrite(led_verde, HIGH);
          digitalWrite(led_amarelo, HIGH);
          digitalWrite(led_vermelho, HIGH);
          break;

          default:
          break;

        }
      }
    }
  }
ultimo_estado_botao1 = leitura_botao1;
ultimo_estado_botao2 = leitura_botao2;      //Define o ultimoestado com o valor de valorlido
}

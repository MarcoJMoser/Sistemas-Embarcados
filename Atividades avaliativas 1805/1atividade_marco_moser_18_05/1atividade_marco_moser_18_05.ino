#include <Ultrasonic.h>  //biblioteca para o sensor ultrassonico HC-SR04

Ultrasonic ultrasonic(4, 5);
int capacidade; // variavel de comparação

const int led_eletro = 9; //led verde
const int sistema_aquecimento = 10; //led azul
const int led_amarelo = 11; // alarme 1
const int led_vermelho = 12; // alarme 2

const int botaoA = 2;
bool estado_botaoA = 1;
bool ultimo_estado_botaoA = 1; // high por conta do pullup interno
unsigned long tempo_botaoA = 0; // define como 0 o tempo qundo apertar o botão 
                                // pra começar a contar o debounce
unsigned long debounce = 50;

const int pot = A1;  // potenciometro na pora analogica A1
int valor_pot = 0;
int valor_temp = 0;

void setup() {
  pinMode(led_eletro, OUTPUT);
  pinMode(sistema_aquecimento, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(pot, INPUT);  // define potnciometro como entrada
  attachInterrupt(digitalPinToInterrupt(botaoA), desligalarme, FALLING);
  Serial.begin(115200);
}

void loop() {
  capacidade = ultrasonic.read();              // le a distancia do sensor como capacidade do tanque 
  valor_pot == analogRead(pot);               //  leitura de porta analogica
  valor_temp == (valor_pot * 50.00) / 1026;  // multiplica por 50 que é o valor máximo e divide por 1026

  if (capacidade > 80 && 25 < valor_temp > 27){ // se a capacidade for maior que 80 e a temperatura igual a 26 a eletrovalvula liga
    digitalWrite(led_eletro, 1);
    Serial.print("Saida de líquido permitida!");
    Serial.print("Capacidade do tanque =");
    Serial.println(capacidade);
    Serial.print("Temperatura Ideal!");
  }
  
  if ( valor_temp < 26 && capacidade > 10){  // se a temperatura for menor que 26 (temp limite/ideal) o sistema de aquecimento liga
    digitalWrite(sistema_aquecimento, 1);
    Serial.print("Sistema de aquecimento ligado!");
  }
  
  if ( capacidade < 40 ){  // se a capacidade do tanque for menor que 20% o primeiro alarme é acionado
    digitalWrite(led_amarelo, 1);
  }

  if(capacidade < 20){ // se a capacidade for menor que 10% o segundo alarme é acionado 
    digitalWrite(led_vermelho, 1);
    Serial.print("Capacidade em nível Crítico");
  }
}


void desligalarme() {
  digitalWrite(led_vermelho, 0);
  // "inicia um reset"
}

/*                                                              EXPLICAÇÃO LÓGICA

led_eletro(eletrovalula) só vai ser acionado quando a capacidade do tanque (leitura em cm do sensor ultrassonico) for maior que 40%(80cm) 

o sistema de aquecimento (led azul) só vai ser acionado assim que a temperatura do líquido for menor que 26 que é o valor ideal que permite o acionamento
da eletrovvula (que permite a saida / passagem de líquido)

o primeiro alarme (led_amarelo) aciona assim que a capacidade do tanque (sensor) for menor que 20%(40cm)

o segundo alarme (led_vermelho) aciona assim que a capacidade do taque (sensor) for menor que 10%(20cm)

o segundo alarme só vai poder ser desligado quando o botao A for pressionado 
o botão A funciona por meio de interrupção 
vai "sair do loop" pra executar outro comando/função

Quando acionar o botao ele desliga o led e inicia o "reset" (nova leitura dos valores)
*/
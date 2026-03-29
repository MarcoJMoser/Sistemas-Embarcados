/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Seleção simples (Leds)

ALuno: Marco josé Moser Cordeiro
Data: 23/03/2023
Versão: 1.0

************************************************************************ */

const int led_vermelho = 5;  // faz com que o led vermelho ali se torne uma consante então ele vai ser sempre igual a 5
const int led_verde = 6;     // então toda vez que a gente se referir a ele na programação ele vai ler com esse valor fixo
const int led_amarelo = 7;   //  como dps a gente configra ele como uma saida dai ele vai ler ele sempre como um output
char led;                    //  cria a variavel led

void setup() {
  pinMode(led_vermelho, OUTPUT);  // define os leds que no caso vão ser as constantes como saida
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  Serial.begin(115200);  // define o valor da velocidade de transmissão de informações do arduin pro terminais
  //  Configura a taxa de transferência em bits por segundo (baud rate) para transmissão serial
  //  no caso vai configurar  velocidade em que o arduino vai procesar a infornação dada na programação
}

void loop() {
  if (Serial.available()) {  // se a serial estive disponivel ( no caso tipo se ela n tiver nada chegando nela ou enfim )
    led = Serial.read();     // a variavel led vai guardar o que a serial vai ler
                             // então ela vai guardar o que a gente mandar pra serial
    if (led == 'R') {
      digitalWrite(led_vermelho, HIGH);
    }
    else if (led == 'r'){
      digitalWrite(led_vermelho, LOW);
    }

    if (led == 'G') {
      digitalWrite(led_verde, HIGH);
    }
    else if (led =='g') {
      digitalWrite(led_verde, LOW);
    }

    if (led == 'Y') {
      digitalWrite(led_amarelo, HIGH);
    }
    else if (led == 'y'){
      digitalWrite(led_amarelo, LOW);
    }

    if (led == 'T'){ // liga todos os leds       
      digitalWrite(led_verde,HIGH);
      digitalWrite(led_amarelo, HIGH);
      digitalWrite(led_vermelho, HIGH);
    }
    else if (led == 't'){  // desliga todos os led
      digitalWrite(led_verde, LOW);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_vermelho, LOW);
    }
    //perguntar pq que ta apagando tão rapido
  }
}

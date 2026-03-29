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

const int led_vermelho = 5; 
const int led_verde = 6;    
const int led_amarelo = 7;   
char led;           

void ligarleds(){                     // cria uma função para todos os leds em uma linha só de código 
  digitalWrite(led_verde, HIGH);      // usa o void pq cria uma variavel que "n retorna valor" 
  digitalWrite(led_amarelo, HIGH);    // só executa a ação sem gerar nada ou resultar em nada como se fosse tipo apertar um botão mesmo
  digitalWrite(led_vermelho, HIGH);   // tu só liga o negócio
}

void desligarleds(){                 // cria a mesma função só que pra desligar 
  digitalWrite(led_verde, LOW);      // o () siginifa que n recebe nenhum valor e só executa o que tem ali dentro dos {}
  digitalWrite(led_amarelo, LOW);    // os () vai ler o que ta ali e executar o que ta ali dentr
  digitalWrite(led_vermelho, LOW);
}

void setup() {
  pinMode(led_vermelho, OUTPUT); 
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  Serial.begin(115200);  
}

void loop() {
  if (Serial.available()) {  
    led = Serial.read();   
   switch(led) { // se a variavel led for igual a os casos tal coisa rola

    case 'R':  // caso led for igual a R o led vermelho acende
    digitalWrite(led_vermelho, HIGH);
    break; // da break na sequencia do código caso o caso seja positivo (tipo se o caso estiver certo)

    case 'r':
    digitalWrite(led_vermelho, LOW);
    break;

    case 'G':
    digitalWrite(led_verde, HIGH);
    break;

    case 'g':
    digitalWrite(led_verde, LOW);
    break;

    case 'Y':
    digitalWrite(led_amarelo, HIGH);
    break;

    case 'y':
    digitalWrite(led_amarelo, LOW);
    break;


    case 'T':
    ligarleds();  // o () "chama" e executa a função como se fosse "apertando o botao"
    // se n tivesse ele é como se eu só tivesse citando um nome tipo o led vermelho e verde 
    // o () vai pler o que ta dentro da funçao lá em cima e executar
    break;

    case 't':
    desligarleds();
    break;

    default:
    desligarleds();
    break;
   }             
  }
}
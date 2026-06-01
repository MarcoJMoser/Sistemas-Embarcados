/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Sistema de bobinamento

Autor: Marco J. Moser C
Data: 20/04/2026
Versão: 1.0

************************************************************************ */
const int led1 = 9;   // led Motor
const int led2 = 10;  // led Verificar

const int botao1 = 2;  // Botao de inicio
const int botao2 = 3;  // botao da contagem
bool estadobotao1 = 1;
bool estadobotao2 = 1;
bool ultimoestado1 = 1;
bool ultimoestado2 = 1;  // primeiro valor (sucetivel ao debounce)
unsigned long tempo1 = 0;
unsigned long tempo2 = 0;  //tempo para o segundo botao
const int debouncetimer = 50;
int contador = 0;  //Cria um contador que inicia no valor 0

unsigned long tempoAnterior = 0;
const int intervalo = 600;
bool estadoLed = LOW;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);  // define os botões como pullup
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int valorlido1 = digitalRead(botao1);
  int valorlido2 = digitalRead(botao2);

  if (valorlido1 != ultimoestado1)  // se o valor lido do botão for diferente do ultimo estado lido (primeiro)
  {
    tempo1 = millis();  //guarda o mili segundo exato da mudança de estado do botao na variavel tempo
                        // atribiu a tempo o valor em mili segundos de quando o botão mudou de estado
  }

  if (millis() - tempo1 > debouncetimer) {
    if (valorlido1 != estadobotao1) {
      valorlido1 = estadobotao1;

      if (estadobotao1 == LOW) {
        digitalWrite(led1, HIGH);  // led motor acionado
      }
    }
  }

  if (valorlido2 != ultimoestado2) {
    tempo2 = millis();
  }

  if (millis() - tempo2 > debouncetimer) {
    if (valorlido2 != estadobotao2) {
      valorlido2 = estadobotao2;

      if (estadobotao2 == LOW) {
        contador++;
        Serial.print("contagem: ");
        Serial.println(contador);
      }
    }
  }
  ultimoestado1 = valorlido1;
  ultimoestado2 = valorlido2;  //Define o ultimoestado com o valor de valorlido

  if (contador == 60) {
    digitalWrite(led1, LOW);

    if (millis() - tempoAnterior >= intervalo) {
      tempoAnterior = millis();

      estadoLed = !estadoLed;         // alterna estado do led pra high
      digitalWrite(led2, estadoLed);  // atribui o valor 1 ao led
      Serial.println("Verificar termino de ciclo!");
    }

    if (estadobotao1 == LOW) {
      contador = 0;
    }
  }
}
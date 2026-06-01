const int pot1 = A0;  //potenciometro 1 na porta analogica A0
const int pot2 = A1;  // potenciometro 2 na pora analogica A1

const int botaoA = 2;  // botao a u botao 1 na porta 2
const int led1 = 9;    // led 1 na porta 9
const int led2 = 10;   // led 2 na porta 10
const int led3 = 11;   // led 3 na porta 11
const int led4 = 12;   // led 4 na porta 12

bool estadobotaoA = 1;         // "valor certo" do botao a
bool ultimoestadoA = 1;        // primeiro valor (sucetivel ao debounce)
unsigned long tempoA = 0;      //tempo para o primeiro botao
const int debouncetimer = 50;  // define o tempo de espera para estabilização da leitura do botão

unsigned long tempoAnterior = 0;
const int intervalo = 500;
bool estadoLed = LOW;


void setup() {
  pinMode(botaoA, INPUT_PULLUP);  // define se o botao vai ser pull up ou down intenamente

  pinMode(pot1, INPUT);  // define potnciometro como entrada
  pinMode(pot2, INPUT);  // define potnciometro como entrada

  pinMode(led1, OUTPUT);  // define o led como saida
  pinMode(led2, OUTPUT);  // define o led como saida

  Serial.begin(115200);  // define velocidade
}

void loop() {
  int valorA = digitalRead(botaoA);

  if (valorA != ultimoestadoA)  // se o valor lido do botão for diferente do ultimo estado lido (primeiro)
  {
    tempoA = millis();  //guarda o mili segundo exato da mudança de estado do botao na variavel tempo
                        // atribiu a tempo o valor em mili segundos de quando o botão mudou de estado
  }

  if (millis() - tempoA > debouncetimer) {
    if (valorA != estadobotaoA) {
      estadobotaoA = valorA;
    }
  }

  int valor_pot1 = analogRead(pot1);                      //  mesma coisa que o digital read utilizado anteriormente
  int valor_porcentagem1 = (valor_pot1 * 100.00) / 1026;  // converte pra porcentagem (0 a 100%)
  Serial.print("Nivel reservatório inferior = ");
  Serial.println(valor_porcentagem1);

  int valor_pot2 = analogRead(pot2);                     //  mesma coisa que o digital read utilizado anteriormente
  int valor_temperatura = (valor_pot2 * 100.00) / 1026;  // converte pra valor de porcentagem que vai ser igual a temp
  Serial.print("Temperatura do motor = ");
  Serial.println(valor_temperatura);


  if (botaoA == LOW && valor_porcentagem1 > 15) {
    digitalWrite(led1, HIGH);
    if (valor_porcentagem1 < 5) {
      digitalWrite(led1, LOW);
    }
  }

  if (valor_temperatura > 80) {
    digitalWrite(led1, LOW);

    if (millis() - tempoAnterior >= intervalo) {
      tempoAnterior = millis();

      estadoLed = !estadoLed;        // alterna estado do led pra high
      digitalWrite(led4, estadoLed); // atribui o valor 1 ao led
      Serial.println("Alarme falha");
    }
  }
  
  if (botaoA == LOW && valor_porcentagem1 > 15 && valor_temperatura < 80){
    digitalWrite(led1, HIGH);
    digitalWrite(led4, LOW);
  } else{
    digitalWrite(led1, LOW);
  }
}
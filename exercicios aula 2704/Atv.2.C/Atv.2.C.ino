const int botao = 2;
const int led = 13;

bool estadoBotao = LOW;
bool ultimoEstado = LOW;

unsigned long ultimoTempo = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  while(true){ // usa o true pq nunca muda então a condição vai ser sempre verdadeira  (loop infinito)
  // usado para esperar um evento (sensor, botao e enfim)
  // da pra usar while(estadoBotao == LOW) mas dai se o valor n atualizar corretamente pode bugar 
    int leitura = digitalRead(botao);

    if(leitura != ultimoEstado){
      ultimoTempo = millis();
    }

    if((millis() - ultimoTempo) > debounceDelay){
      if(leitura != estadoBotao){
        estadoBotao = leitura;

        if(estadoBotao == HIGH){
          Serial.println("Botão pressionado");
          digitalWrite(led, HIGH);
          break; // sai do while
        }
      }
    }

    ultimoEstado = leitura;
  }
}

void loop() {
}
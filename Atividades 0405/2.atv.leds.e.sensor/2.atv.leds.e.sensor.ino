#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);
int distance;
const int botao1 = 2;
const int led1 = 8;
const int led2 = 9;
const int led3 = 10;
const int led4 = 11;

const int botao1 = 2;
const int botao2 = 3;
bool estado_botao1 = 1;
bool estado_botao2 = 1;
bool ultimo_estado_botao1 = 1; // high por conta do pullup interno
bool ultimo_estado_botao2 = 1;  // high por conta do pullup interno
unsigned long tempo_botao1 = 0; // define como 0 o tempo qundo apertar o botão 
                                // pra começar a contar o debounce
unsigned long tempo_botao2 = 0;
unsigned long debounce = 50;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);

  
  Serial.begin(9600);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  bool action = !(digitalRead(botao1));
  if(action){
    if(distance > 40){
      digitalWrite(led1, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
    }
    else if(distance > 30){
      digitalWrite(led1, 1);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
    }
    else if(distance > 20){
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
    }
    else if(distance > 10){
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 0);
    }
    else if(distance > 0){
      digitalWrite(led1, 1);
      digitalWrite(led2, 1);
      digitalWrite(led3, 1);
      digitalWrite(led4, 1);
    }
  }
  else{
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
    digitalWrite(led4, 0);
  }
}

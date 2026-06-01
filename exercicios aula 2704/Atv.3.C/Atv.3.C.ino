int leds[5] = {8, 9, 10, 11, 12};   // faz um vetor pros 5 leds

void setup() {
  for(int i = 0; i < 5; i++){   //configura todos eles em uma linha só usando laço for
    pinMode(leds[i], OUTPUT);   // le uma vez só e seta como saida
  }
}

void loop() {
  for(int i = 0; i < 5; i++){    // liga todos conforme valor da variavel i 
    digitalWrite(leds[i], HIGH); // se i for um vai ligar só um led 
    delay(300);                  //
    digitalWrite(leds[i], LOW);
  }
}
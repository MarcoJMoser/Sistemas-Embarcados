int leds[3] = {8, 9, 10}; // cria uma variavel/vetor

void setup() {
  for(int i = 0; i < 3; i++){   // configura todos os leds
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {    // da pra fazer só com for mas dai tem que fazer outra variavel pra colocar os tempos diferentes 
  // VERDE
  digitalWrite(leds[2], HIGH); // ligado no 10
  delay(3000);
  digitalWrite(leds[2], LOW);

  // AMARELO
  digitalWrite(leds[1], HIGH); // ligado no 9
  delay(1000);
  digitalWrite(leds[1], LOW);

  // VERMELHO
  digitalWrite(leds[0], HIGH); // ligado no 8
  delay(3000);
  digitalWrite(leds[0], LOW);
}



/* FEITO SÓ COM O FOR 

int leds[3] = {8, 9, 10}; // vermelho, amarelo, verde
int tempos[3] = {3000, 1000, 3000}; // tempos de cada um

void setup() {
  for(int i = 0; i < 3; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for(int i = 2; i >= 0; i--){ // verde → amarelo → vermelho
    digitalWrite(leds[i], HIGH);
    delay(tempos[i]);
    digitalWrite(leds[i], LOW);
  }
}


*/
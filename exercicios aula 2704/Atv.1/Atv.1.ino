  int leds [3] = {8, 9, 10};
  // define os pinos dos tres leds em uma linha só
  // o led do 8 vai ser o 0 e o 9 o 1 e o 10 o 2 
  
  void setup() {
    for (int j = 0; j < 3; j ++){
      pinMode(leds[j], OUTPUT);
    }
}

void loop() {
  for (int i = 0; i < 20; i ++){
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
    delay(200);
  }

}

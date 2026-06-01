const int ledPin = 9;
const int interruptPin = 2;
bool state = LOW;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blink, CHANGE); /*
  attachInterrupt confgura a interrupçao como o pinMode so que com strutura de for
  o primeiro ali de digitalPinToInterrut serve pra caso erre a entrada isso n permita que o código
  rode 
  o segundo é o nome da interrupção 
  o terceiro vai ser um dos 4 estados do arduino uno (LOW, RISING, FALLING, CHANGE)
  */ 

}

void loop() {
  digitalWrite(ledPin, state);
}

void blink(){
  state = !state;
}

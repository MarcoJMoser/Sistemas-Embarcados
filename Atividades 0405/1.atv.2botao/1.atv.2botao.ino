// um botao liga o led e o outro deliga 

const int ledPin = 9;
const int interruptPin1 = 2;
const int interruptPin2 = 3;  // botao 2
bool state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin1, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blink, FALLING); // botao 1
  attachInterrupt(digitalPinToInterrupt(3), twink, FALLING); // coloca outra interrupção
}

void loop() {
  digitalWrite(ledPin, state);
}

void blink(){
  state = 1;
}

void twink(){
  state = 0;
}
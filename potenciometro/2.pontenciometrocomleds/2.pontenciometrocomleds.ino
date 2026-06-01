int potenciometro = A0;
unsigned int valor_potenciometro = 0; // só pega valores positivos
float valor_volts = 0; // define ua variavel que comporta numero quebrado
const int led1 = 9;
const int led2 = 10;
const int led3 = 11;

void desligarleds() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

void ligarleds() {
  digitalWrite(led1, 1);
  digitalWrite(led2, 1);
  digitalWrite(led3, 1);
}

void setup() {
  pinMode(potenciometro, INPUT);
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}


void loop() {
  valor_potenciometro = analogRead(potenciometro);  //  mesma coisa que o digital read utilizado anteriormente
  valor_volts = (valor_potenciometro*5.00)/1026;
  Serial.print("valor analógico = ");
  Serial.println(valor_potenciometro);
  Serial.print("valor_volts = ");
  Serial.println(valor_volts);

  if (valor_volts >= 4){
    ligarleds();
  } 
  else if (valor_volts >= 3 ){
    digitalWrite(led1, 0);
    digitalWrite(led2, 0);
    digitalWrite(led3, 1);
  }
  else if (valor_volts >=2 ){
    digitalWrite(led1, 0);
    digitalWrite(led2, 1);
    digitalWrite(led3, 0);
  }
  else if (valor_volts >= 1 ){
    digitalWrite(led1, 1);
    digitalWrite(led2, 0);
    digitalWrite(led3, 0);
  }
  else if (valor_volts < 1){
    desligarleds();
  }
}
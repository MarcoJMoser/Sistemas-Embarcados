int sensor = A0;
int valor_sensor = 0;
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
  pinMode(sensor, INPUT);
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}


void loop() {
  valor_sensor = analogRead(sensor);  //  mesma coisa que o digital read utilizado anteriormente
  Serial.print("Valor analógico = ");
  Serial.println(valor_sensor);
  delay(200); 


  if (valor_sensor <= 204) { // se o valor analógico for menor ou igual a 204 apaga todos os leds
    desligarleds();
  }

  if (204 <= valor_sensor < 409){
    digitalWrite(led1 , 1);
  }

  if (409 <= valor_sensor < 613){
    digitalWrite(led2, 1);
  }

  if (613 <= valor_sensor < 819){
    digitalWrite(led3, 1);
  }

  if (819 <= valor_sensor){
    ligarleds();
  }
}
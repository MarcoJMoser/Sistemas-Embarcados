int sensores[4] = {A0, A1, A2, A3};  // faz um vetor pra todos 

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 4; i++){
    int valor = analogRead(sensores[i]); // cria uma variavel pra guardar o valor lido de i 
    // se i for 0 vai ler o sensor 0(A0) e guardar o valor dele 
    Serial.print("Sensor ");             // aqui mostra o sensor que ta senod lido 
    Serial.print(i);                     // como ta no laço i vai falar qual é entçao se i for 1 vai ser A1 e etc
    Serial.print(": ");           
    Serial.println(valor);               // mostra o valor na serial 
  } 

  delay(1000);
}
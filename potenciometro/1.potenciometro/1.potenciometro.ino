int sensor = A0;
int valor_sensor = 0;  // armazena em uma inteira para ter espaço
                       //  pq o valor n cabe no bolean já que ultrapassa os bits 
                        // da certo para usar ni int pq cabe até 32000 e ele ocup ate 1023

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(115200);
}


void loop() {
  valor_sensor = analogRead(sensor);  //  mesma coisa que o digital read utilizado anteriormente
  Serial.print("Valor analógico = ");
  Serial.println(valor_sensor);
  delay(200); 
}

//  código pra ler  valor digital do sensor ali analógio e ver commo ele vai se transformar
//  5v = 1023
//  2,5 = 511 
//  e por ai vai dai ele pelo conversor vai tranformar esse sinal analogico em digital 
//  pela quantização (ver isso melhor)
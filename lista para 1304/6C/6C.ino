const int sensorNTC = A0;
const int led4 = 11;

unsigned int valorSensor = 0;

// valor de referência 
const int limite = 600;  

unsigned long tempoAnterior = 0;
const int intervalo = 100;

bool estadoLed = LOW;

void setup() {
  pinMode(sensorNTC, INPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  // ===== LEITURA DO SENSOR =====
  valorSensor = analogRead(sensorNTC);

  Serial.print("Valor NTC: ");
  Serial.println(valorSensor);

  // ===== VERIFICA TEMPERATURA =====
  if (valorSensor > limite) {

    // pisca sem delay
    if (millis() - tempoAnterior >= intervalo) {
      tempoAnterior = millis();

      estadoLed = !estadoLed; // alterna estado do led pra high
      digitalWrite(led4, estadoLed);
    }

  } else {
    // abaixo da temperatura → LED apagado
    digitalWrite(led4, LOW);
  }

}
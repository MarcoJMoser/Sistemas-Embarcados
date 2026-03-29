const int led_vermelho = 5;  
const int led_verde = 6;  
const int led_amarelo = 7;    
//
const int pin_botao1 = 2;
const int pin_botao2 = 3;
bool botao1 = false,  botao2 = false; // coloca assim pra fazer tudo em uma linha e ocupar menos espaço 
// 0 é pressionado e 1 é solto         

void setup() {
  pinMode(pin_botao1, INPUT_PULLUP); 
  pinMode(pin_botao2, INPUT_PULLUP); // define se o botao vai ser pull up ou down intenamente
  Serial.begin(115200);
  pinMode(led_vermelho, OUTPUT);  
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
}

void loop() {
  botao1 = digitalRead(pin_botao1);
  botao2 = digitalRead(pin_botao2);
  //
  if (botao1 == 0 && botao2 == 0){
    digitalWrite(led_vermelho, HIGH);  
  } 
  else {
    digitalWrite(led_vermelho, LOW);
  }
  if (botao1 == 0 || botao2 == 0){
    digitalWrite(led_verde, HIGH);
  }
  else {
    digitalWrite(led_verde, LOW);
  }
}
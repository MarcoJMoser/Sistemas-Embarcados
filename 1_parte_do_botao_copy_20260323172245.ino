
const int pin_botao = 2;
bool botao = false;  // define como boleana pq o botão é boleano ( no caso só 1 e 0)

const int led_vermelho == 5;  
const int led_verde == 6;     
char led; 


void setup() 
{
  pinMode(pin_botao, INPUT_PULLUP);  // define se o botao vai ser pull up ou down intenamente
  Serial.begin(115200);
}

void loop() {
  botao = digitalRead(pin_botao);  // a variavel botao vai guardar o que vier no botão
  if (botao == LOW); // se ele tiver solto (no caso ai dai fica = a 0)
  {
    Serial.println("botao pressionado"); //prita na serial a mensgaem ali
  }
}

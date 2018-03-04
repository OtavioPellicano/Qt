# Qt
Simples demonstração da utilização de Signal e Slots e comunicação serial
Para testar o programa, enviei o código abaixo para o arduino

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(1);
}

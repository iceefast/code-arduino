#define pinSensor 7
#define pinBotao 0 // Int 0 = Pino2
//volatile int contador = 0;
int cont;


void setup() {
attachInterrupt(pinBotao,reset,RISING);
  cont=100;
  pinMode(pinBotao, INPUT);
  Serial.begin(9600);

}




void loop() 
{
  for(cont=100;cont>0;cont--)
{
  Serial.println(cont);
  delay(500);
}

Serial.println("Reiniciando contagem");
}


void reset(){
cont = 100;
}



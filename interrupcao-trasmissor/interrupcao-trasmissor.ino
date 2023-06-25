#include <VirtualWire.h>

#define pinSensor 0 //int 0 = pino 2
#define pinRF  3
#define pinLED 13

volatile int contador = 0;

struct tipoPacote {
  int valor1;
};

tipoPacote pacote; 

void setup() {
  Serial.begin(9600);
  pinMode(pinLED, OUTPUT);
  pinMode(pinSensor, INPUT); // possivel pino do sensor 
  attachInterrupt(pinSensor,Vazao,RISING);

  vw_set_tx_pin(pinRF);
  vw_set_ptt_inverted(true);
  vw_setup(1500);
  interrupts();
  Serial.println("aguardando dado:");


}

void loop() {
 
if(contador == 450) 
{
  pacote.valor1 = 1; //valor ml


  vw_send((uint8_t *)&pacote, sizeof(pacote));
  vw_wait_tx();

  contador = 0;
  
  digitalWrite(pinLED,HIGH);
  delay(300);
  digitalWrite(pinLED, LOW);
  
}

}

void Vazao()
{
  contador ++;
  Serial.println(contador);
  //noInterrupts();
  
}


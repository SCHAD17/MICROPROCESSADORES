#include <IRremote.h>
#include <LiquidCrystal.h>
#define receptor 11
#define relepin 13


int state = LOW; // o status do rele é baixo 
float codigo;

IRrecv recIR(receptor);
decode_results resultado;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
lcd.begin(16,2); // Inicialização do lcd
recIR.enableIRIn(); // Inicialização do receptor
pinMode(relepin, OUTPUT);
lcd.setCursor(0,0);
lcd.print("Codigo Lido no Re");

}
// Função Aciona rele para acionar o nosso rele quando um sinal mandado
void acionaRele(){
  int relepin_state = digitalRead(relepin); // ele pega a estatuto  atual no pino do rele
  digitalWrite(relepin, !relepin_state); // aqui vai mudar o estatutos ou seja se fosse 0 ele vai para 1 
  }
void loop() {
  if (recIR.decode(&resultado)){
    codigo = (resultado.value);
      /*if (16580863==codigo){
       acionaRele();
    }*/
    acionaRele();
    lcd.setCursor(5,1);
    lcd.print(resultado.value, HEX);
    //lcd.print(codigo, HEX); // codigo transformado em decimal
    recIR.resume();
    }

}

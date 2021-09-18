/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
void setup() {
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

}

unsigned char Va1 =45;
unsigned char Va2 =0x33;
unsigned char Va3;
unsigned char Vb1 =0x31;
unsigned char Vb2 =23;
unsigned char Vb3;
unsigned char Vc1 =45;
unsigned char Vc2 =0x33;
unsigned char Vc3;
unsigned char Vd1 =0x31;
unsigned char Vd2;

void LEDs(unsigned num){
	int V[6]={13,12,11,10,9,8};
		int i;
		int bit;
		for (i=0; i<6; i++){
			bit=bitRead(num,i);
				digitalWrite(V[i], bit);
				            }
                         }
// the loop function runs over and over again forever


void loop() {           

	Va3 = Va1 & Va2;
		LEDs(Va3);
			delay(20000);
	
	Vb3 = Vb1 | Vb2;
		LEDs(Vb3);
			delay(15000);
	
	Vc3 = Vc1 ^ Vc2;
		LEDs(Vc3);
			delay(10000);
	
	Vd2 = ~Vd1;
		LEDs(Vd2);
			delay(5000);
	 
}

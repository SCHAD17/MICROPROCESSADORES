#include <Arduino.h>
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}
boolean result1;
boolean result2;
boolean result3;
boolean result4;
boolean result5;
boolean result6;
boolean result7;
boolean result8;
boolean result9;

// the loop function runs over and over again forever
void loop() {

// 1 situação

 result1 = (4==3);
 if (result1 == true)
	digitalWrite(13, HIGH); // aqui caso o resultado for verdade o Led 13 ascende,
			else
				digitalWrite(13, LOW);  // caso nao for o led fica desligado.
	
// 2 situação

result2 = (3==3);
	if (result2 == true)
		digitalWrite(12, HIGH); // aqui caso o resultado for verdade o Led 12 ascende,
			else
				digitalWrite(12, LOW);  // caso nao for o led fica desligado.
// 3 situação

result3 = (7>=3);
	if (result3 == true)
		digitalWrite(11, HIGH); // aqui caso o resultado for verdade o Led 11 ascende,
			else
				digitalWrite(11, LOW);  // caso nao for o led fica desligado.

// 4 situação

result4 = (4<=3);
	if (result4 == true)
		digitalWrite(10, HIGH); // aqui caso o resultado for verdade o Led 10 ascende,
			else
				digitalWrite(10, LOW);  // caso nao for o led fica desligado.

// 5 situação

result5 = (4!=3);
	if (result5 == true)
		digitalWrite(9, HIGH); // aqui caso o resultado for verdade o Led 09 ascende,
			else
				digitalWrite(9, LOW);  // caso nao for o led fica desligado.

// 6 situação 

result6 = (4>3);
	if (result6 == true)
		digitalWrite(8, HIGH); // aqui caso o resultado for verdade o Led 08 ascende,
			else
				digitalWrite(8, LOW);  // caso nao for o led fica desligado.

// 7 situação

result7 = (3>1) && (2==2);
	if (result7 == true)
		digitalWrite(7, HIGH); // aqui caso o resultado for verdade o Led 07 ascende,
			else
				digitalWrite(7, LOW);  // caso nao for o led fica desligado.

// 8 situação

result8 = (3>7) || (2==2);
	if (result8 == true)
		digitalWrite(6, HIGH); // aqui caso o resultado for verdade o Led 07 ascende,
			else
				digitalWrite(6, LOW);  // caso nao for o led fica desligado.

// 9 situação

result9 = !((3>1) && (2==2));
	if (result9 == true)
		digitalWrite(5, HIGH); // aqui caso o resultado for verdade o Led 07 ascende,
			else
				digitalWrite(5, LOW);  // caso nao for o led fica desligado.


	delay(10000);
}

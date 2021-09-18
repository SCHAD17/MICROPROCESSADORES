/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <LiquidCrystal.h>
#include <TimerOne.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio


void Valores();
float fun_media(float soma, int qtdTotal);
float fun_soma(float val);
float soma_2;
float media_2;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

int sizeVet;
int cont = 0;
int qtdSobrescrito = 0;
int qtdTotal = 0;
float *vet; 
float val = 0;
float somaTotal = 0;
long int randomNumber = 0;
int sensorPin = A0;   // Pino A0 do sensor 
float valor = 0;
float temperatura = 0;
int ledPin = 11; // Pino do led

void setup() {
  
  pinMode(sensorPin, INPUT);
  randomSeed(analogRead(A0));
  randomNumber = random(30,51);
  lcd.begin(16, 2); //inicializaçao do lcd
  vet = (float*) malloc(randomNumber*sizeof(float));
  for(int i = 0; i<randomNumber; i++){
    vet[i] = 0;  
  }
  Timer1.attachInterrupt(Valores,12000000); 
}

void Valores(){
  val = analogRead(sensorPin);
    temperatura = map(val, 0, 1023, -50, 125); // Mapeando o valor lido na porta A0 para valor de temperatura entre -50 ate 125°C.
      valor = map(val, 0, 1023, 0, 255);  // Mapeamento para o pino do PWM que é de 8 bits, -256 até 255.
        analogWrite(ledPin, valor);
  if(cont>=randomNumber){
    cont = 0;
      qtdSobrescrito++;
        }
  vet[cont] = val;
    cont++;
  qtdTotal++;
  
  float soma_2 = fun_soma(val);
  float media_2 = fun_media(soma_2,qtdTotal);
  
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("TEMP");      // Valores lidos
  lcd.setCursor(0,1);
  lcd.print(temperatura);  // Temperatura lidos
  lcd.setCursor(5,0);
  lcd.print("Q_LID");      // Quantidade de valores lidos
  lcd.setCursor(7,1);
  lcd.print(qtdTotal);
  lcd.setCursor(11,0);
  lcd.print("Q_SOB");     // Quantidade de valores sobreescritos
  lcd.setCursor(13,1);
  lcd.print(qtdSobrescrito);
  /*
  lcd.setCursor(13,0);   
  lcd.print("MED");      // Média dos valores
  lcd.setCursor(13,1);
  lcd.print(media2/204.6);*/
  lcd.display();
  Timer1.initialize(12000000);
}
// definição das funções média e soma
// Função para Fazer a média

float fun_media(float soma,int qtdTotal){
  return soma/qtdTotal;
}
// Função para Fazer a soma

float fun_soma(float val){
  somaTotal = val + somaTotal;
  return somaTotal;
} 
void loop(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SOMA");      // Soma dos valores lidos 
    lcd.setCursor(0,1);
    lcd.print(soma_2/204.6);
    lcd.setCursor(5,0);
    lcd.print("MEDIA");
    lcd.setCursor(7,1);
    lcd.print(media_2);
    lcd.display();
    lcd.setCursor(11,0);
    lcd.print("T_VET");      // Tamanho do vetor
    lcd.setCursor(13,1);
    lcd.print(randomNumber);
    lcd.display();
    delay(15000);
  }

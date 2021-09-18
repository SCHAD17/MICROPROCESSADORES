#include <LiquidCrystal.h>
#include <TimerOne.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 

int sizeVet;
int cont = 0;
int qtdSobrescrito = 0;
int qtdTotal = 0;
float *vet;
float val = 0;
float somaTotal = 0;
long int randomNumber = 0;
const int sensorPin = A0;

void setup() {
  randomSeed(analogRead(A0));
  randomNumber = random(20,51);
  lcd.begin(16, 2);
  vet = (float*) malloc(randomNumber*sizeof(float));
  for(int i = 0; i<randomNumber; i++){
    vet[i] = 0;  
  }
  Serial.begin(9600);
  Timer1.attachInterrupt(Valores,30000000);
}

void Valores(){
  val = analogRead(sensorPin);
  
  if(cont>=randomNumber){
    cont = 0;
      qtdSobrescrito++;
        }
  vet[cont] = val;
  cont++;
  qtdTotal++;
  float soma2 = fun_soma(val);
  float media2 = fun_media(soma2,qtdTotal);
  lcd.setCursor(0,0); 
  lcd.print("VAL");      // Valores lidos
  lcd.setCursor(0,1);
  lcd.print(val/204.6);
  lcd.setCursor(4,0);
  lcd.print("SOB");      // Quantidade de valores sobrescritos
  lcd.setCursor(5,1);
  lcd.print(qtdSobrescrito);
  lcd.setCursor(8,0);
  lcd.print("SOMA");     // Soma dos valores
  lcd.setCursor(7,1);
  lcd.print(soma2/204.6);
  lcd.setCursor(13,0);   
  lcd.print("MED");      // Média dos valores
  lcd.setCursor(13,1);
  lcd.print(media2/204.6);
  lcd.display();
  Timer1.initialize(5000000);
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
  }

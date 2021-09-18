#include <LiquidCrystal.h>
#include <TimerOne.h>


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int ndispositivos = 0;
float grausC;

int sizeVet;
int cont = 0;
int qtdSobrescrito = 0;
int qtdTotal = 0;
float *vet;
float val = 0;
float somaTotal = 0;
long int randomNumber = 0;
int sensorPin = A0;
void setup() {

  randomSeed(analogRead(A0));
  randomNumber = random(30,51);
  
  lcd.begin(16, 2);
  vet = (float*) malloc(randomNumber*sizeof(float));
  for(int i = 0; i<randomNumber; i++){
    vet[i] = 0;  
  }
  
  //pinMode(11, INPUT);
  pinMode(A0, INPUT);
  
  Timer1.attachInterrupt(leValores,1000000);
}

float media(float soma,int qtdTotal){
  return soma/qtdTotal;
}

float soma(float val){
  somaTotal = val + somaTotal;
  return somaTotal;
} 

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return round((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}


void leValores(){
  val = analogRead(sensorPin);
  
  if(cont>=randomNumber){
    cont = 0;
    qtdSobrescrito++;
  }
  vet[cont] = val;
  cont++;
  qtdTotal++;
  analogWrite(11,128);
  
  float soma2 = soma(val);
  float media2 = media(soma2,qtdTotal);
  lcd.setCursor(0, 0);
  lcd.print(String(qtdTotal)+" ");
  lcd.print(String(qtdSobrescrito)+" ");
  lcd.print(String(soma2)+" ");
  lcd.print(String(media2));
  lcd.setCursor(0, 1);
  lcd.print(String(grausC)+" ");
  lcd.display();
  
  
  Timer1.initialize(5000000);
}

void loop() {
  //lcd.setCursor(0, 1);
  //int val=analogRead(A0);
  //Serial.println(val);
}

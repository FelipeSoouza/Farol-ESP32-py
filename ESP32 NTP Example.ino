int Red = 23; 
int Yellow = 19;
int Green = 18;
int pedvermelho = 4; 
int pedverde = 2;
int botao = 15; 
unsigned long changeTime; 
int i;

#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 20
#define LCD_LINES   4

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

int led[] = {13, 12, 14, 33, 32, 26, 27}; //g,f,e,d,c,b,a
int nove[] = {0,0,1,0,0,0,0};
int oito[] = {0,0,0,0,0,0,0};
int sete[] = {1,1,1,1,0,0,0};
int seis[] = {0,0,0,0,0,1,0};
int cinco[] = {0,0,1,0,0,1,0};
int quatro[] = {0,0,1,1,0,0,1};
int tres[] = {0,1,1,0,0,0,0};
int dois[] = {0,1,0,0,1,0,0};
int um[] = {1,1,1,1,0,0,1};
int zero[] = {1,0,0,0,0,0,0};


void setup(){
lcd.init(); 
 lcd.backlight();
 

 pinMode(Red, OUTPUT);
 pinMode(Yellow, OUTPUT);
 pinMode(Green, OUTPUT);
 pinMode(pedvermelho, OUTPUT);
 pinMode(pedverde, OUTPUT);
 pinMode(botao, INPUT_PULLUP);
 for(int i = 0; i < 7; i++) pinMode(led[i], OUTPUT);
 digitalWrite(Green, HIGH);
 digitalWrite(pedvermelho, HIGH);

 for(int i = 20; i > 0; i--){
    lcd.setCursor(0,0);
   lcd.print("CARROS ON: ");
   lcd.setCursor(7,1);
   lcd.print(i);
    delay(1000);
    lcd.clear();
 }
 lcd.clear();
 lcd.print("BOTAO PRONTO");
}


void loop(){
  while(true){
    int teste = digitalRead(botao);
    if(teste == LOW && (millis() - changeTime) > 20000){
      display();
    }
  }
}

void display(){
  visor();
  lcd.clear();
 delay(100);
 lcd.print("SINAL AMARELO ON");
 digitalWrite(Green, LOW); 
 digitalWrite(Yellow, HIGH); 
 delay(2000); 
   lcd.clear();
 delay(100);
 lcd.setCursor(0,0);
 lcd.print("VERMELHO ON");
 lcd.setCursor(0,1);
 lcd.print("AMARELO OFF");
 delay(1000);
 digitalWrite(Yellow, LOW); 
 digitalWrite(Red, HIGH); 
 delay(1000); 
  lcd.clear();
 delay(100);
 lcd.print("PEDESTRE ON");
 digitalWrite(pedvermelho, LOW); 
 digitalWrite(pedverde, HIGH); 
 delay(500);

 contagem();

lcd.clear();
delay(100);
lcd.print("SINAL FECHANDO");
 for (int x=0; x<10; x++) {
   digitalWrite(pedverde, HIGH);
   delay(250);
   digitalWrite(pedverde, LOW);
   delay(250);
} 
lcd.clear();
delay(100);
lcd.print("PEDESTRE FECHOU");
 digitalWrite(pedvermelho, HIGH);
 delay(500);
 digitalWrite(Red, LOW);
 digitalWrite(Green, HIGH); 
 changeTime = millis();
 lcd.clear();
delay(100);
lcd.print("SINAL ABRIU");
delay(1000);
inicio();
 loop();
}

void contagem(){
  for(int i = 0; i < 7; i++) digitalWrite(led[i], nove[i]);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("9");
  delay(1000);
  for(int i = 0; i < 7; i++) digitalWrite(led[i], oito[i]);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("8");
  delay(1000);
  for(int i = 0; i < 7; i++) digitalWrite(led[i], sete[i]);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("7");
  delay(1000);
  for(int i = 0; i < 7; i++) digitalWrite(led[i], seis[i]);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("6");
  delay(1000);
  for(int i = 0; i < 7; i++) digitalWrite(led[i], cinco[i]);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("5");
  delay(1000);
  for(int i = 0; i < 7; i++) digitalWrite(led[i], quatro[i]);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("4");
  delay(1000);
  for(int i = 0; i < 7; i++) digitalWrite(led[i], tres[i]);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("3");
  delay(1000);
  for(int i = 0; i < 7; i++) digitalWrite(led[i], dois[i]);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("2");
  delay(1000);
  for(int i = 0; i < 7; i++) digitalWrite(led[i], um[i]);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("1");
  delay(1000);
  for(int i = 0; i < 7; i++) digitalWrite(led[i], zero[i]);
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PEDESTRE ABERTO");
  lcd.setCursor(7,1);
  lcd.print("0");
  delay(1000); 
}

void visor(){
  lcd.home();
  digitalWrite(Green, HIGH);
  digitalWrite(pedvermelho, HIGH);
  lcd.print( " carros passando ");
  lcd.setCursor(0, 1);
  lcd.print( " verde ");
  lcd.setCursor(6, 1);
  lcd.print((millis()-changeTime)/1000);

}

void inicio(){
  for(int i = 20; i > 0; i--){
    lcd.setCursor(0,0);
   lcd.print("CARROS ON: ");
   lcd.setCursor(7,1);
   lcd.print(i);
    delay(1000);
    lcd.clear();
  }
  lcd.clear();
  lcd.print("BOTAO PRONTO");
}
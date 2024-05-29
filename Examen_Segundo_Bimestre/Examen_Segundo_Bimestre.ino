/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AV 
   Curso: Taller 
   Proyecto: Examen 
   Dev: Juan Ignacio Maldonado Rodriguez
   Fecha: 17/05/2024
*/
#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int pin1 = 13;
const int pin2 = 10;
const int pin3 = 11;
const int pin4 = 12;
const int A = 2;
const int B = 3;
const int C = 4;
const int D = 5;
const int E = 6;
const int F = 7;
const int G = 8;
const int led1 = A0;
const int led2 = A1;
const int led3 = A2;
const int led4 = A3;
const byte FILAS = 4;
const byte COLUMNAS = 4;
const int a = 25;
#define LCD_ADDRESS 0x27  
#define LCD_ROWS 2              
#define LCD_COLUMNS 16

Servo miservo; 
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS); 

char keys[FILAS][COLUMNAS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pinesFilas[FILAS] = {8, 7, 6, 5};
byte pinesColumnas[COLUMNAS] = {4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Juan Ignacio");
  lcd.setCursor(0, 1);
  lcd.print("Examen II");
  miservo.attach(9);
  Serial.begin(9600);
}

void loop() { 
  char key = keypad.getKey();
  if (key) {
    switch (key) {
      case '1':
        contarAscendente();
        break;
      case '2':
        contarDescendente();
        break;
      case '3':
        autoFantastico();
        break;
      case '4':
        Display();
        break;
      case '5':
        servo();
        break;
    }
  }
}

void contarAscendente() {
  for (int i = 0; i <= 99; i++) {
    Serial.println(i);
    delay(500);
  }
}

void contarDescendente() {
  for (int i = 99; i >= 0; i--) {
    Serial.println(i);
    delay(500);
  }
}

void autoFantastico() {
  int leds[] = {led1, led2, led3, led4};
  int numLeds = sizeof(leds) / sizeof(leds[0]);

  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
    delay(200);
  }

  for (int i = numLeds - 2; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(200);
    digitalWrite(leds[i], LOW);
    delay(200);
  }
}

void Display() {
  mostrarNumero(1);
  delay(1000);
  mostrarNumero(2);
  delay(1000);
  mostrarNumero(3);
  delay(1000);
  mostrarNumero(4);
  delay(1000);
  mostrarNumero(5);
  delay(1000);
  mostrarNumero(6);
  delay(1000); 
}

void mostrarNumero(int numero) {
  int binario[4];

  for (int i = 0; i < 4; i++) {
    binario[i] = numero % 2;
    numero /= 2;
  }

  digitalWrite(pin1, binario[0]);
  digitalWrite(pin2, binario[1]);
  digitalWrite(pin3, binario[2]);
  digitalWrite(pin4, binario[3]);
}

void servo() {
  for (int pinpwm = 0; pinpwm <= 180; pinpwm++) {
    miservo.write(pinpwm);
    delay(20);
  }
  for (int pinpwm = 180; pinpwm >= 0; pinpwm--) {
    miservo.write(pinpwm);
    delay(20);
  }
}

#include <Adafruit_LiquidCrystal.h>
int solar_celda = 0;//inicializamos la celda.
Adafruit_LiquidCrystal lcd_1(0);// pinA0

void setup()
{
  pinMode(A0, INPUT);////asigna el pin como entrada para la celda.
  Serial.begin(9600);
  lcd_1.begin(16,2);
}

void loop()
{
  solar_celda = (analogRead(A0) * (5.001 / 1023.001));
  Serial.println(solar_celda);
  lcd_1.setCursor(0,0);
  lcd_1.print("Vol Celda Solar");
  lcd_1.setCursor(0,1);
  lcd_1.print("Valor = ");
  lcd_1.setCursor(10,1);
  lcd_1.print(solar_celda);
  delay(10);
}
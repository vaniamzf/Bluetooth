/*
  Koneksi pin LCD:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5 ==>10
 * LCD D5 pin to digital pin 4 ==> 9
 * LCD D6 pin to digital pin 3 ==> 8
 * LCD D7 pin to digital pin 2 ==> 7
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

const int pinLDR = A0;



void setup()
{  
  lcd.begin(16, 2); // set up jumlah kolom dan baris LCD:
  // Tampilkan kalimat pembuka di LCD:
  Serial.begin(9600);
  pinMode(pinLDR, INPUT);
//  pinMode(7, OUTPUT);
}

int dataLDR = 0;
void loop()
{     
  dataLDR = analogRead(pinLDR);
  
  lcd.setCursor(0, 0);
  lcd.print("dataLDR: ");
  lcd.print(dataLDR);
  Serial.println(dataLDR);
  
  lcd.setCursor(0, 1);
  lcd.print("Kondisi: ");
  if(dataLDR < 150){
    lcd.println("GELAP  ");
    digitalWrite(7, LOW);
  }
  else if(dataLDR < 300){
    lcd.println("REDUP  ");
    digitalWrite(7, LOW);
  }
  else if(dataLDR < 450){
    lcd.println("TERANG ");
    digitalWrite(7, LOW);  
  }
  else{
    lcd.println("SILAU  ");
    digitalWrite(7, HIGH);
  }
  delay(500);
  //Tampilkan nilai LDR di LCD baris kedua
//  lcd.clear();
//  lcd.setCursor(0, 1);
//  lcd.print(suhu);
//  delay(50);
}

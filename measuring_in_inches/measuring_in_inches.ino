#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define trigPin 12
#define echoPin 8
void setup()
{
  pinMode(trigPin, OUTPUT);  //The transmit pin of the ultrasonic sensor
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.

  lcd.backlight();
  lcd.print("aseem at");
  lcd.setCursor(0,1);
  lcd.print("innovation");
  delay(3000);
  lcd.clear();
}

void loop()
{
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.01350 / 2;
  lcd.setCursor(0, 0);
  lcd.backlight();
  lcd.print("distance from OB");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print("inch");
  delay(200);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.backlight();
  lcd.print("distance from OB");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print("inch");
}

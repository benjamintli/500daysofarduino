#include <Time.h>
#include <TimeLib.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
int timeUp = 7, timeDown = 8, buttonUp, buttonDown, initialPress, finalPress;

void setup() {
  // put your setup code here, to run once:
  pinMode(timeUp, INPUT);
  pinMode(timeDown, INPUT);
  lcd.begin (16, 2);
  lcd.print ("TIME:");
  setTime (13, 30, 50, 22, 5, 2017);
}

void printDigits (int digits, char type)
{

  if (type == 'm' || type == 's')
  {
    lcd.print (":");
  }
  if (digits < 10)
  {
    lcd.print ("0");
  }
  lcd.print (digits);

}

void timeAdjust ()
{
  buttonUp = digitalRead(timeUp);
  buttonDown = digitalRead (timeDown);
  if (buttonUp == HIGH)
  {
    adjustTime (60);
    delay (100);
  }
  if (buttonDown == HIGH)
  {
    adjustTime (-60);
    delay (100);
  }
}
void digitalClock ()
{
  timeAdjust();
  printDigits (hour(), 'h');
  printDigits (minute(), 'm');
  printDigits (second(), 's');
  if (isAM() == true)
  {
    lcd.setCursor (14, 0);
    lcd.print ("AM");
  }
  else
  {
    lcd.setCursor (14, 0);
    lcd.print ("PM");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor (6, 0);
  //timeAdjust();
  digitalClock();
  //delay (1000);
}

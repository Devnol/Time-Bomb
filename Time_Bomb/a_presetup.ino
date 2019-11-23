#include <LiquidCrystal.h> // LiquidCrystal can be found on Tools > manage libraries
#include <CountUpDownTimer.h> //CountUpDownTimer by AndrewMascolo can be found on his github page: https://github.com/AndrewMascolo/CountUpDownTimer
const int BuzzerPin = 9; //assigns the pin the buzzer is in
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7; //assigns the appropriate pins to names for the lcd pins
int BuzzFreq = 100; //initial buzzer frequency for the siren sequence
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //lcd register select, enable and data pins 4-7 are used by the lcd
CountUpDownTimer T(DOWN); //makes a new timer named "T" and sets it to countdown
void beepity(){ //does the beeping sound every second
      tone(BuzzerPin, 3000);
      delay(100);
      noTone(BuzzerPin);
      delay(900);
    }
void siren(){ //does the siren sound after the time is up
  do{ //increments the frequency
   BuzzFreq = BuzzFreq + 20;
   tone(BuzzerPin,BuzzFreq);
   Serial.println(BuzzFreq);
   Serial.print("frequency:");
   delay(1);
  } while (BuzzFreq < 3500);

  do{ //decrements the frequency
   BuzzFreq = BuzzFreq - 20;
   tone(BuzzerPin,BuzzFreq);
   Serial.println(BuzzFreq);
   Serial.print("frequency:");
   delay(1);
  } while (BuzzFreq > 100);
}

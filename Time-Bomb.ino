#include <LiquidCrystal_I2C.h> // LiquidCrystal_I2C by Frank de Brabander can be found under Tools > Manage Libraries in the Arduino IDE
#include <CountUpDownTimer.h> // CountUpDownTimer by AndrewMascolo can be found on its GitHub repo: https://github.com/AndrewMascolo/CountUpDownTimer
#include <Wire.h> // Wire is a built-in Arduino IDE library

//pin assignments, adjust to your needs
const uint8_t Buzzer = 9; //must support PWM
const uint8_t LeftBtn = 10;
const uint8_t MiddleBtn = 11;
const uint8_t RightBtn = 12;
//lcd information, adjust to your needs
const uint8_t LcdAddr = 0x3F; //Address of the I2c device, for more info in how to find that see File > Examples > Wire > i2c_scanner in the Arduino IDE
const uint8_t LcdCols = 16; //Columns of characters your LCD has, usually 16 or 20
const uint8_t LcdRows = 2; //Rows of characters your LCD has, usually 2 or 4
uint16_t BuzzFreq = 100; //initial buzzer frequency for the siren sequence

//main code - do not edit unless you know what you're doing

LiquidCrystal_I2C lcd(LcdAddr, LcdCols, LcdRows); //initialise display as lcd
CountUpDownTimer T(DOWN); //makes a new timer named "T" and sets it to countdown

void tick(){ //does the beeping sound every second
    tone(Buzzer, 3000);
    delay(100);
    noTone(Buzzer);
    delay(900);
}

void siren(){ //does the siren sound after the time is up
    do { //increments the frequency
        BuzzFreq = BuzzFreq + 5;
        tone(Buzzer, BuzzFreq);
        delay(1);
    } while (BuzzFreq < 3500);

    do { //decrements the frequency
        BuzzFreq = BuzzFreq - 5;
        tone(Buzzer, BuzzFreq);
        delay(1);
    } while (BuzzFreq > 100);
}

void setup() { 
    //initialize lcd screen
    lcd.init();
    // turn on the backlight
    lcd.backlight();
    tick();
    pinMode(Buzzer,OUTPUT);
    pinMode(LeftBtn,INPUT);
    pinMode(MiddleBtn,INPUT);
    pinMode(RightBtn,INPUT);

    //Time Select code goes here
    T.SetTimer(10); //set the time the you want the bomb to run for in seconds.
    T.StartTimer();       
}

void loop() {
   T.Timer();
   if (T.TimeHasChanged() ){    
     lcd.setCursor(0, 0); //col, row
     lcd.print("You have ");
     lcd.print(T.ShowMinutes());
     lcd.print(":");
     lcd.print(T.ShowSeconds());
     lcd.print(" to");
     lcd.setCursor(0, 1);
     lcd.print("clear the area");
     tick();
   }
   else if (T.ShowTotalSeconds() == 0){
     lcd.clear();
     lcd.print("Evaquate the");
     lcd.setCursor(0, 1);
     lcd.print("building!");
     siren();
   }
}
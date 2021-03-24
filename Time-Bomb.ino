//pin assignments, adjust to your needs
const uint8_t Buzzer = 9; //must support PWM
const uint8_t LeftBtn = 10;
const uint8_t MiddleBtn = 11;
const uint8_t RightBtn = 12;
//lcd information, adjust to your needs
const uint8_t LcdAddr = 0x3F; //Address of the I2c device, for more info in how to find that see File > Examples > Wire > i2c_scanner in the Arduino IDE
const uint8_t LcdCols = 16; //Columns of characters your LCD has, usually 16 or 20
const uint8_t LcdRows = 2; //Rows of characters your LCD has, usually 2 or 4
uint8_t time = 0; //if you don't use buttons replace 0 with a different number (in seconds)

//DO NOT EDIT BELOW THIS LINE (unless you know what you're doing)

#include <LiquidCrystal_I2C.h> // LiquidCrystal_I2C by Frank de Brabander can be found under Tools > Manage Libraries in the Arduino IDE
#include <CountUpDownTimer.h> // CountUpDownTimer by AndrewMascolo can be found on its GitHub repo: https://github.com/AndrewMascolo/CountUpDownTimer
#include <Wire.h> // Wire is a built-in Arduino IDE library

LiquidCrystal_I2C lcd(LcdAddr, LcdCols, LcdRows); //initialise display as lcd
CountUpDownTimer T(DOWN); //makes a new timer named "T" and sets it to countdown

void tick(){ //does the beeping sound every second
    tone(Buzzer, 3000);
    delay(100);
    noTone(Buzzer);
    delay(900);
}

void siren(){ //does the siren sound after the time is up
    uint16_t BuzzFreq = 100; //initial buzzer frequency for the siren sequence
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

uint8_t getTime() {
    uint8_t setTime = 60;
    while (!digitalRead(MiddleBtn)) {
        if (digitalRead(LeftBtn)) {
            setTime--;
        } else if (digitalRead(RightBtn)) {
            setTime++;
        }
        lcd.setCursor(0, 0);
        lcd.print("Set Time: " + String(setTime));
        lcd.setCursor(0, 1);
        lcd.print("Seconds");
        delay(50);
        lcd.clear();
    }
    return setTime;
}

void setup() {
    tick();
    pinMode(Buzzer,OUTPUT);
    pinMode(LeftBtn,INPUT);
    pinMode(MiddleBtn,INPUT);
    pinMode(RightBtn,INPUT);
    lcd.init(); //initialize lcd screen
    lcd.backlight(); // turn on the backlight
    if (!time) time = getTime(); // if time hasn't been set by the user, run getTime() to obtain it.
    T.SetTimer(time); 
    T.StartTimer();       
}

void loop() {
    if (T.ShowTotalSeconds() == 0){
        lcd.print("Kaboom lawl");
        while(true) siren();
    }

    T.Timer();
    lcd.setCursor(0, 0); //col, row
    lcd.print("You have ");
    lcd.print(T.ShowMinutes());
    lcd.print(":");
    lcd.print(T.ShowSeconds());
    lcd.setCursor(0, 1);
    lcd.print("to evacuate");
    tick();
    lcd.clear();
}
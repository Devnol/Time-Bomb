void setup() { 
    pinMode(BuzzerPin,OUTPUT);
    Serial.begin(9600);
    Serial.println();
    lcd.begin(16,2);  //col,row   
     T.SetTimer(10); //set the time the you want the bomb to run for in seconds.
     T.StartTimer();       
}

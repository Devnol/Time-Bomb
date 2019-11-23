void loop() {
   T.Timer();
   if (T.TimeHasChanged() ){    
     Serial.print(T.ShowMinutes());
     Serial.print(":");
     Serial.println(T.ShowSeconds());
     lcd.setCursor(0, 0); //col, row
     lcd.print("You have ");
     lcd.print(T.ShowMinutes());
     lcd.print(":");
     lcd.print(T.ShowSeconds());
     lcd.print(" to");
     lcd.setCursor(0, 1);
     lcd.print("clear the area");
     beepity();
   }
   else if (T.isTimerRunning() == false){
     lcd.clear();
     lcd.print("Evaquate the");
     lcd.setCursor(0, 1);
     lcd.print("building!");
     Serial.println("detonated");
     siren();
   }
}

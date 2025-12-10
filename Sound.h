void killSound(){
  tone(buzzer, 262);
  delay(50);
  noTone(buzzer);   

  tone(buzzer,523);
  delay(50);
  noTone(buzzer);   
}


void damageSound(){
  tone(buzzer, 262);
  delay(50);
  noTone(buzzer);   

  tone(buzzer,117);
  delay(50);
  noTone(buzzer);   
}


void gameOverSound(){
  tone(buzzer, 262);
  delay(50);
  noTone(buzzer);   

  tone(buzzer,65);
  delay(200);
  noTone(buzzer);   

  tone(buzzer, 262);
  delay(50);
  noTone(buzzer);   

  tone(buzzer,65);
  delay(200);
  noTone(buzzer);   

  tone(buzzer, 262);
  delay(50);
  noTone(buzzer);   

  tone(buzzer,65);
  delay(200);
  noTone(buzzer);   
}
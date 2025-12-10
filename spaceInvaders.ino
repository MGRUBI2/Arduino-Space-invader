#include "Init.h"




void setup() {

  enemyFleet.initRandom(); //fleet.h lib

  pinMode(healthLed1,OUTPUT);
  pinMode(healthLed2,OUTPUT);
  pinMode(healthLed3,OUTPUT);
  pinMode(buzzer,OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.createChar(0,playerChar);  
  lcd.createChar(5,bulletChar);

  lcd.createChar(1,enemyVar1Char);
  lcd.createChar(2,enemyVar2Char);
  lcd.createChar(3,enemyVar3Char);

  pinMode(shootLeftBtn,INPUT_PULLUP);
  pinMode(shootRightBtn,INPUT_PULLUP);

  Serial.begin(9600);

}



void loop() {
  if(!isRoundRunning) //loop is spinning while waiting player input so function random() could work better.
    startScreen();

  else{

    player.drawPlayer();

    enemyFleet.drawFleet();

    player.shoot();

    player.healthCheck();

    enemyFleet.colisionCheck(player);

    enemyFleet.npcSpawner(player);
    
  }

  delay(150);
  lcd.clear();
}



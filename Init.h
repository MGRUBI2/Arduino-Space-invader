#include <LiquidCrystal_I2C.h>

#if defined(ARDUINO) && ARDUINO >= 100//copyed from LiquidCrystal I2C example for custom chars
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

#define analogX A1
#define analogY A0
#define shootLeftBtn 2
#define shootRightBtn 3
#define healthLed1 9
#define healthLed2 10
#define healthLed3 11
#define buzzer A3

enum Direction{
  left,
  right
};

LiquidCrystal_I2C lcd(0x27,16,2);


int isRoundRunning=false;

#include "Sound.h"
#include "Bullet.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "Fleet.h"

PlayerShip player;
Fleet enemyFleet;


uint8_t playerChar[8] = {0b00100,0b01110,0b11111,0b10101,0b11111,0b01110,0b00100, 0b00000};
uint8_t bulletChar[8]  = {0x0,0x0,0x0,0x3,0x3,0x0,0x0,0x0};

uint8_t enemyVar1Char[8] = {0b00100,0b01110,0b10101,0b11111,0b01110,0b01010,0b10001,0b00000};
uint8_t enemyVar2Char[8] = {0b01110,0b11111,0b10101,0b11111,0b11111,0b01010,0b10101,0b00000};
uint8_t enemyVar3Char[8] = {0b00100,0b01110,0b10101,0b11111,0b10101,0b00100,0b01010,0b00000};


void startScreen(){
  

  if(digitalRead(shootLeftBtn)==0 || digitalRead(shootRightBtn)==0)
    isRoundRunning=true;

  enemyFleet.fleetInit();
  
  lcd.setCursor(0,0);
  lcd.printstr("Press button");

  lcd.setCursor(0,1);
  lcd.printstr("to start");
}
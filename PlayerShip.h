int inputX;
int inputY;

#define fullHealth 3

class PlayerShip {
  int x,y;
  int health=fullHealth;
  int score=0;
  Bullet Lbullet;
  Bullet Rbullet;
public:
  int getx(){return y;}//i switched x with y in begining and too lazy to refactor at moment
  int gety(){return x;}
  int getScore(){return score;}
  int increseScore(int value){score+=value;}
  int getHealth(){return health;}
  int lowerHealth(){health--;}
  Bullet getLeftBullet(){return Lbullet;}
  Bullet getRightBullet(){return Rbullet;}
  void destroyRightBullet(){Rbullet.inFlight=false;}
  void destroyLeftBullet(){Lbullet.inFlight=false;}

  PlayerShip() { 
    x=0;
    y=7;
  }

  void scoreScreen(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("score:");

    lcd.setCursor(0,1);
    lcd.print(score);
    delay(3000);
  }

  void healthCheck(){
    healthState();

    if (health==0){
      gameOverSound();
      isRoundRunning=false;
      health=fullHealth;
      scoreScreen();
      score=0;
      x=0;
      y=7;
    }
  }

  void healthState(){
    analogWrite(healthLed1, health >= 1 ? 50 : LOW);
    analogWrite(healthLed2, health >= 2 ? 50 : LOW);
    analogWrite(healthLed3, health >= 3 ? 50 : LOW);
  }

  void drawPlayer(){

    if (analogRead(analogX)<300)
      inputX=0;
    else if (analogRead(analogX)>600)
      inputX=2;
    else
      inputX=1;

    if (analogRead(analogY)<300)
      inputY=0;
    else if (analogRead(analogY)>600)
      inputY=2;
    else
      inputY=1;

    if (inputX==0)
      x=1;
    else if(inputX==2)
      x=0;

    if (inputY==0)
      y--;
    else if(inputY==2)
      y++;

    if (y<0)
      y=0;

    if (y>15)
      y=15;

    lcd.setCursor(y,x);

    lcd.printByte(0);
    

    Rbullet.drawBullet();
    Lbullet.drawBullet();

  }

  void shoot(){
    if(digitalRead(shootLeftBtn)==0){
        if(Lbullet.inFlight==false){
          Lbullet.inFlight=true;
          Lbullet.y=x;
          Lbullet.x=y;
        }
      }

    if(Lbullet.inFlight==true){
      if(Lbullet.x==0){
        Lbullet.inFlight=false;
        return;
      }

      Lbullet.x--;
    }



    if(digitalRead(shootRightBtn)==0){
        if(Rbullet.inFlight==false){
          Rbullet.inFlight=true;
          Rbullet.y=x;
          Rbullet.x=y;
        }
      }

    if(Rbullet.inFlight==true){
      if(Rbullet.x==15){
        Rbullet.inFlight=false;
        return;
      }

      Rbullet.x++;
    }
  } 

};
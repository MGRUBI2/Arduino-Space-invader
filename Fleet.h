#define maxSize 10
#define startSize 2
#define numOfVariants 4 //from 1 to 4 (4 not included)

class Fleet{
  EnemyShip fleet[maxSize];
  int currentSize; //size based on score. bigger score brings more enemys
public:

  void fleetInit(){//game starts with 2 enemys
    currentSize=startSize;

    fleet[0]=EnemyShip(random(0,2),random(1,numOfVariants));
    fleet[1]=EnemyShip(random(2,4),random(1,numOfVariants));
    
  }

  void drawFleet(){
    for(int i=0;i<currentSize;i++){
      if(!fleet[i].getIsDestroyed()){
        fleet[i].advance();
        fleet[i].drawEnemy();
      }
    }
  }

  void colisionCheck(PlayerShip &player){
    for (int i=0;i<currentSize;i++){
        if(fleet[i].getIsDestroyed())
          continue;
        
        if(player.getLeftBullet().getx()==fleet[i].getx() && player.getLeftBullet().gety()==fleet[i].gety()){
          fleet[i].destroy();
          killSound();
          player.destroyLeftBullet();
          Serial.println(player.getLeftBullet().isInFlight());
          
          switch (fleet[i].getVariant()){
            case 1:
              player.increseScore(10);
              break;
            case 2:
              player.increseScore(20);
              break;
            case 3:
              player.increseScore(30);
              break;
          }
        }

        if(player.getRightBullet().getx()==fleet[i].getx() && player.getRightBullet().gety()==fleet[i].gety()){
          fleet[i].destroy();
          killSound();
          player.destroyRightBullet();

          switch (fleet[i].getVariant()){
            case 1:
              player.increseScore(10);
              break;
            case 2:
              player.increseScore(20);
              break;
            case 3:
              player.increseScore(30);
              break;
          }
        }


        if(player.getx()==fleet[i].getx() && player.gety()==fleet[i].gety()){
          player.lowerHealth();
          damageSound();
          fleet[i].destroy();
        }
     
        if(fleet[i].getx()>15 || (fleet[i].getx()==0 && fleet[i].getDirection()==left)){
          fleet[i].destroy();
        }
    }     
    
  }

  void npcSpawner(PlayerShip player){
      if (player.getScore()>5000)
        currentSize=maxSize;

      else if (player.getScore()>2000)
        currentSize=8;

      else if (player.getScore()>1000)
        currentSize=6;

      else if (player.getScore()>100)
        currentSize=4;

      for (int i=0;i<currentSize;i++){
        if (fleet[i].getIsDestroyed() && random(3)==0){// 1/3 chances of spawning
          fleet[i]=EnemyShip(random(4),random(1,numOfVariants));
          break;
        }
      }

    }

   void initRandom(){
     randomSeed(analogRead(A3));//input noise is used as seed
  } 
};



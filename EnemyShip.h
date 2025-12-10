class EnemyShip {
  int x,y;
  int variant;//variant 1 just goes straight, var2 has 1/4 chances to go up/down, var 3 goes up/down constantly
  int startPosition;
  int movmentAdjuster=4;//moves every n game loops
  bool isDestroyed;
  Direction directions;

public:
  int getx(){return x;}
  int gety(){return y;}
  bool getIsDestroyed(){return isDestroyed;}
  int getVariant(){return variant;}
  Direction getDirection() {return directions;}

  EnemyShip(){ }

  void destroy(){
    isDestroyed=true;
  }

  EnemyShip(int pos, int var){

    variant=var;   
    startPosition=pos;
    isDestroyed=false;
    

    switch (startPosition){
      case 0:
        x=0;
        y=0;
        break;
      case 1:
        x=15;
        y=0;
        break;
      case 2:
        x=0;
        y=1;
        break;
      case 3:
        x=15;
        y=1;
        break;
    }

  }

    void variant2Movment(){//var2 has 1/4 chances to go up/down
          if(random(0,4)==0){
            if (y==1)
              y=0;
            else
              y=1;
          }
    }

    void variant3Movment(){//var 3 goes up/down constantly
            if (y==1)
              y=0;
            else
            y=1;
    }

  void movment(Direction dir){ 
    directions=dir;
    switch (variant){
      case 1:
        if (directions==left)
          x--;
        else
          x++;
        break;
      case 2:
        if (directions==left){
          variant2Movment();
          x--;
        }
        else{
          variant2Movment();
          x++;
        }
        break;
      case 3:
        if (directions==left){
          variant3Movment();
          x--;
          }
        else{
          variant3Movment();
          x++;
        }
        break;

    }
  }

  void advance(){
    switch (startPosition){
      case 0:
        if(movmentAdjuster==0){
          movmentAdjuster=4;
          movment(right);
        }
        else{
          directions=right;//this is quick fix for bug that removes npc at begining position
          movmentAdjuster--;
        }
        break;

      case 1:
          if(movmentAdjuster==0){
          movmentAdjuster=4;
          movment(left);
          }
        else
          movmentAdjuster--;
        break;

      case 2:
          if(movmentAdjuster==0){
          movmentAdjuster=4;
          movment(right);
          }
        else{
          directions=right;//this is quick fix for bug that removes npc at begining position
          movmentAdjuster--;
        }
        break;

      case 3:
        if(movmentAdjuster==0){
          movmentAdjuster=4;
          movment(left);
        }
        else
          movmentAdjuster--;
        break;
    }

  }

  void drawEnemy(){
      lcd.setCursor(x,y);
      lcd.printByte(variant);
  }
};
class Bullet{
protected:
  int y=-1,x=-1;// value is set like this for quick bug fix related to spawn kill
  bool inFlight=false;
  friend class PlayerShip;

  public:

  int gety(){return y;}
  int getx(){return x;}
  bool isInFlight(){return inFlight;}

  void drawBullet(){

    if(!inFlight)
      return;

    lcd.setCursor(x,y);

    lcd.printByte(5);
  }
};
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;
class Item; 

class Room{
 public:
  Room(int);
  Room(int, Item*);
  Room(int, bool);
  char* getDescription();//done
  bool isItemGone();//done
  char* pickUpItem();
  int getID();//done
  void getExits();//done
  bool isLocked();//done
  void unlock();//done
 private:
  char description[1000];//description of room
  Item* myitem;//room's item
  int ID;//rooms ID number
  bool locked;
  bool itemPickedUp;
};

#endif

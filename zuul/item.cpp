#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

Item::Item(char* itemName){//items are created with name as a parameter
  name = itemName;
}

char* Item::getName(){//returns name
  return name;
}

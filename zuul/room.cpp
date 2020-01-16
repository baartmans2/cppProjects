//room.cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

Room::Room(int theID)//basic room constructor
{
    ID = theID;
    locked = false;
    itemPickedUp = true;
}

Room::Room(int theID, Item* theItem)//advanced room constructor
{
    ID = theID;
    myitem = theItem;
    locked = false;
    itemPickedUp = false;
}

Room::Room(int theID, bool lock)//constructor for end room
{
    ID = theID;
    locked = lock;
    itemPickedUp = true;
}

int Room::getID()
{
    return ID;
}

char* Room::pickUpItem()//picks up item
{
    itemPickedUp = true;
    return myitem->getName();
}

void Room::unlock()//unused
{
    locked = false;
}

bool Room::isItemGone()//check if item has been picked up
{
    return itemPickedUp;
}

char* Room::getDescription()//get room description
{
  return description;
}

bool Room::isLocked()//pretty sure this is unused
{
    return locked;
}

void Room::getExits()//get the room exits based on the ID number.
{
    if (ID == 1)
    {
        cout << "There are exits east and south." << endl;
    }
    else if (ID == 5)
    {
        cout << "There are exits west and south." << endl;
    }
    else if (ID == 11)
    {
        cout << "There are exits north and east." << endl;
    }
    else if (ID >= 2 && ID <= 4)
    {
        cout << "There are exits west, south, and east." << endl;
    }
    else if (ID == 6)
    {
        cout << "There are exits north, south, and east." << endl;
    }
    else if (ID == 10)
    {
        cout << "There are exits north, south, and west." << endl;
    }
    else if (ID >= 7 && ID <= 9)
    {
        cout << "There are exits in all four directions." << endl;
    }
    else if (ID >= 12 && ID <= 14)
    {
        cout << "There are exits north, east, and west." << endl;
    }
}

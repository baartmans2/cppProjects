//raymond baartmans
//11/17/2019
//zuul

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"


using namespace std;

int main()
{
    int keys = 0;//keeps track of the keys you have
    int location = 1;//keeps track of location
    bool gameover = false;//for ending the game
    char input;
    
    vector<Room*> therooms;//holds all the rooms
    
  //Create all rooms and assign them IDs, items, or lock them
  Room* room1 = new Room(1);//creates room object
  strcpy(room1->getDescription(), "You are in the front lobby of a mysterious building you've been exploring.");
  therooms.push_back(room1);
  
  Room* room2 = new Room(2);
  strcpy(room2->getDescription(), "You are in a room full of dusty paintings.");
  therooms.push_back(room2);
  
  Room* room3 = new Room(3);
  strcpy(room3->getDescription(), "You are in a red hallway.");
  therooms.push_back(room3);
  
  Item* key1 = new Item((char*)"Bronze Key");//item creation
  Room* room4 = new Room(4, key1);
  strcpy(room4->getDescription(), "You are in a room full of antiques.");
  therooms.push_back(room4);
  
  Room* room5 = new Room(5);
  strcpy(room5->getDescription(), "You are in a room covered in spidewebs. Ew.");
  therooms.push_back(room5);
  
  Room* room6 = new Room(6);
  strcpy(room6->getDescription(), "You are in what appears to be a laundry room.");
  therooms.push_back(room6);
  
  Item* key2 = new Item((char*)"Silver Key");
  Room* room7 = new Room(7, key2);
  strcpy(room7->getDescription(), "You are in an old kitchen.");
  therooms.push_back(room7);
  
  Room* room8 = new Room(8);
  strcpy(room8->getDescription(), "You are in a room with lots of computers.");
  therooms.push_back(room8);
  
  Room* room9 = new Room(9);
  strcpy(room9->getDescription(), "You are in a blue hallway.");
  therooms.push_back(room9);
  
  Item* key3 = new Item((char*)"Gold Key");
  Room* room10 = new Room(10, key3);
  strcpy(room10->getDescription(), "You are in a room full of shredded papers. Something doesn't seem right here.");
  therooms.push_back(room10);
  
  Item* key4 = new Item((char*)"Emerald Key");
  Room* room11 = new Room(11, key4);
  strcpy(room11->getDescription(), "You are in an empty room with a singular desk in the middle. It looks like it used to have a lot of stuff in it.");
  therooms.push_back(room11);
  
  Room* room12 = new Room(12);
  strcpy(room12->getDescription(), "You are in a orange hallway.");
  therooms.push_back(room12);
  
  Room* room13 = new Room(13);
  strcpy(room13->getDescription(), "You are in an exercise room. This hasn't been used in decades.");
  therooms.push_back(room13);
 
  Item* key5 = new Item((char*)"Diamond Key");
  Room* room14 = new Room(14, key5);
  strcpy(room14->getDescription(), "You are in a room filled with knick knacks.");
  therooms.push_back(room14);
  
  Room* room15 = new Room(15, true);
  strcpy(room15->getDescription(), "");
  therooms.push_back(room15);

  cout << "Welcome to ZUUL." << endl;//message plays on openings

  while (!gameover)//loop to run until game is won.
    {
      if (location == 15)//ending message
        {
            cout << "With all the keys in your hand, you put your hand to the door..." << endl;
            cout << "Suddenly, you slip on a puddle and violently fall forward and collide with the door!" << endl;
            cout << "'Wait a second...' you say as you notice the door is now slightly cracked open." << endl;
            cout << "The door was never locked! It was just jammed. What a waste of time. And these keys- they must be from Dollar Tree." << endl;
            cout << "You look inside the room.........and its the bathroom. That makes you mad." << endl;
            cout << "You go home." << endl << endl;
            cout << "Game Over." << endl;
            gameover = true;
            return 0;
        }
        
      cout << therooms[location - 1]->getDescription() << endl;//display room description
      therooms[location - 1]->getExits();//display room exits
      if (therooms[location - 1]->isItemGone() == false)//if there is an item that hasn't been picked up
        {
            
            cout << "There is an Item. Would you like to pick it up? Type 'y' for yes, and type anything else for no." << endl;
            cin >> input;
            cin.clear();
            cin.ignore(1000000, '\n');
            
            if (input == 'y')//pick up item
            {
                cout << "You picked up the ";
                cout << therooms[location - 1]->pickUpItem();
                cout << "." << endl;
                keys++;//add to keys
            }
            else
            {
                cout << "You ignored the item." << endl;
            }
        }
        
        
      cout << "Which way would you like to go? Type 'w' for west, 'e' for east, 's' for south, or 'n' for north." << endl;//get direction input
        cin >> input;
        cin.clear();
        cin.ignore(1000000, '\n');

	//move player. Check to make sure the player made a valid move. Then update location.
        if (input == 'n')
        {
            if (location >= 1 && location <= 5)
            {
                cout << "You can't go north here." << endl;
            }
            else
            {
                location = location - 5;
            }
        }
        else if (input == 's')
        {
            if (location >= 11 && location <= 15)
            {
                cout << "You can't go south here." << endl;
            }
            else
            {
	      if (location == 10 && keys < 5)//if player tries to move to room 15, the locked room
                {
                    cout << "The door is locked..." << endl;
                }
                else
                {
                    location = location + 5;
                }
            }
        }
        else if (input == 'w')
        {
            if (location == 1 || location == 6 || location == 11)
            {
                cout << "You can't go west here." << endl;
            }
            else
            {
                
                location = location - 1;
            }
        }
        else if (input == 'e')
        {
            if (location == 5 || location == 10 || location == 15)
            {
                cout << "You can't go east here." << endl;
            }
            else
            {
	      if (location == 14 && keys < 5)//if player tries to move to room 15, the locked room
                {
                    cout << "The door is locked..." << endl;
                }
                else
                {
                    location = location + 1;
                }
            }
        }
        else//invalid input
        {
            cout << "Invalid input. Try again." << endl;
        }
        
    }
 

  return 0;
}


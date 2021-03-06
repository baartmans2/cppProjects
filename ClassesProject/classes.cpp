//05 classes
//raymond baartmans
//11/04/19



#include <cstdint>
#include <iostream>
#include <string.h>
#include <vector>
#include <iomanip>
#include "videogames.h"
#include "music.h"
#include "media.h"
#include "movies.h"

using namespace std;

//functions

//add- adds media
void ADD(vector<Media*>* media) {
  char input[15];
  cout << "Would you like to add a videogame, movie, or music" << endl;
  cin.get(input, 15);
  cin.clear();
  cin.ignore(1000000, '\n');
  if((strcmp(input, "movie")) == 0) {//add movie
    Movie* movie = new Movie();

    cout << "Title: ";
    cin.get(movie->getTitle(), 100);
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Year: ";
    cin >> *movie->getYear();
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Director: ";
    cin.get(movie->getDirector(), 50);
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Duration: ";
    cin >> *movie->getDuration();
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Rating: ";
    cin >> *movie->getRating();
    cin.clear();
    cin.ignore(10000, '\n');

    media->push_back(movie);
  }
  else if((strcmp(input, "music")) == 0) {//add music
    Music* song = new Music();

    cout << "Title: ";
    cin.get(song->getTitle(), 100);
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Year: ";
    cin >> *song->getYear();
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Artist: ";
    cin.get(song->getArtist(), 50);
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Length: ";
    cin >> *song->getLength();
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Publisher: ";
    cin.get(song->getPublisher(), 100);
    cin.clear();
    cin.ignore(10000, '\n');

    media->push_back(song);
  }
  else if((strcmp(input, "videogame")) == 0) {//add videogames
    VideoGames* game = new VideoGames();
    
    cout << "Title: ";
    cin.get(game->getTitle(), 100);
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Year: ";
    cin >> *game->getYear();
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Maker: ";
    cin.get(game->getMaker(), 50);
    cin.clear();
    cin.ignore(10000, '\n');

    cout << "Rating: ";
    cin >> *game->getRating();
    cin.clear();
    cin.ignore(10000, '\n');

    media->push_back(game);
  }
  else {//user didnt give correct input
    cout << "Invalid input. Valid inputs are movie, videogame, or music." << endl;
  }
}

void SEARCH(char* title, vector<Media*>* media) {//look is the the search function. This function takes argument to search by title
  vector<Media*>::iterator a;// go through media and search for matching title
  for(a = media->begin(); a != media->end(); ++a) {
    if(strcmp(title, (*a)->getTitle()) == 0) {
	cout << endl << "Title: " << (*a)->getTitle() << endl;
	cout << "Year: " << *(*a)->getYear() << endl;
	if((*a)->getType() == 0) {
	  cout << "Movie" << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*a)->getDirector() << endl;
	  cout << "Duration: " << *reinterpret_cast<Movie*>(*a)->getDuration() << endl;
	  cout << "Rating: " << *reinterpret_cast<Movie*>(*a)->getRating() << endl;
 	}
	else if((*a)->getType() == 1) {
	  cout << "Videogame" << endl;
	  cout << "Maker: " << dynamic_cast<VideoGames*>(*a)->getMaker() << endl;
	  cout << "Rating: " << *reinterpret_cast<VideoGames*>(*a)->getRating() << endl;
	}
	else if((*a)->getType() == 2) {
	  cout << "Music" << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*a)->getArtist() << endl;
	  cout << "Length: " << *reinterpret_cast<Music*>(*a)->getLength() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*a)->getPublisher() << endl;
	}
      }
  }
}
void DELETE(char* title, vector<Media*>* media) {//delete removes a media. this delete function searches by title
  char input[10];
  vector<Media*>::iterator b;//search through media for matching title, then ask user to delete.
  for(b = media->begin(); b != media->end(); ++b) {
    if(strcmp(title, (*b)->getTitle()) == 0) {
      cout << endl << "The Title: " << (*b)->getTitle() << endl;
      cout << "The Year: " << *(*b)->getYear() << endl;
      	if((*b)->getType() == 0) {
	  cout << "Director: " << dynamic_cast<Movie*>(*b)->getDirector() << endl;
	  cout << "Duration: " << *reinterpret_cast<Movie*>(*b)->getDuration() << endl;
	  cout << "Rating: " << *reinterpret_cast<Movie*>(*b)->getRating() << endl;
 	}
	else if((*b)->getType() == 1) {
	  cout << "Maker: " << dynamic_cast<VideoGames*>(*b)->getMaker() << endl;
	  cout << "Rating: " << *reinterpret_cast<VideoGames*>(*b)->getRating() << endl;
	}
	else if((*b)->getType() == 2) {
	  cout << "Artist: " << dynamic_cast<Music*>(*b)->getArtist() << endl;
	  cout << "Length: " << *reinterpret_cast<Music*>(*b)->getLength() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*b)->getPublisher() << endl;
	}
	cout << "Delete? y = yes, n = no.";
	cin.get(input, 10);
	cin.clear();
	cin.ignore(10000, '\n');

	if(strcmp(input, "y") == 0) {
	  delete *b;
	  b = media->erase(b);
	  return;
	}
      }
    }
  }

void SEARCH(int year, vector<Media*>* media) {//this is the same as the first look function except that it searches by year instead of title.
  vector<Media*>::iterator a;//search through media and look for matching year, then display the values of the media.
  for(a = media->begin(); a != media->end(); ++a) {
    if(year == *(*a)->getYear()) {
	cout << endl << "Title: " << (*a)->getTitle() << endl;
	cout << "Year: " << *(*a)->getYear() << endl;
	if((*a)->getType() == 0) {
	  cout << "Movie" << endl;
	  cout << "Director: " << dynamic_cast<Movie*>(*a)->getDirector() << endl;
	  cout << "Duration: " << *reinterpret_cast<Movie*>(*a)->getDuration() << endl;
	  cout << "Rating: " << *reinterpret_cast<Movie*>(*a)->getRating() << endl;
 	}
	else if((*a)->getType() == 1) {
	  cout << "Videogame" << endl;
	  cout << "Maker: " << dynamic_cast<VideoGames*>(*a)->getMaker() << endl;
	  cout << "Rating: " << *reinterpret_cast<VideoGames*>(*a)->getRating() << endl;
	}
	else if((*a)->getType() == 2) {
	  cout << "Music" << endl;
	  cout << "Artist: " << dynamic_cast<Music*>(*a)->getArtist() << endl;
	  cout << "Length: " << *reinterpret_cast<Music*>(*a)->getLength() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*a)->getPublisher() << endl;
	}
      }
    }
 }

void DELETE(int year, vector<Media*>* media) {// this delete function is the same as the first delete function except that it searches by year instead of by title. 
     char input[10];
     vector<Media*>::iterator b;//search through media and find matching year, then ask user if he wants to delete. 
  for(b = media->begin(); b != media->end(); ++b) {
    if(year == *(*b)->getYear()) {
      cout << endl << "The Title: " << (*b)->getTitle() << endl;
      cout << "The Year: " << *(*b)->getYear() << endl;
      	if((*b)->getType() == 0) {
	  cout << "Director: " << dynamic_cast<Movie*>(*b)->getDirector() << endl;
	  cout << "Duration: " << *reinterpret_cast<Movie*>(*b)->getDuration() << endl;
	  cout << "Rating: " << *reinterpret_cast<Movie*>(*b)->getRating() << endl;
	}
	else if((*b)->getType() == 1) {
	  cout << "Maker: " << dynamic_cast<VideoGames*>(*b)->getMaker() << endl;
	  cout << "Rating: " << *reinterpret_cast<VideoGames*>(*b)->getRating() << endl;
	}
	else if((*b)->getType() == 2) {
	  cout << "Artist: " << dynamic_cast<Music*>(*b)->getArtist() << endl;
	  cout << "Length: " << *reinterpret_cast<Music*>(*b)->getLength() << endl;
	  cout << "Publisher: " << dynamic_cast<Music*>(*b)->getPublisher() << endl;
	}
	cout << "Delete? y = yes, n = no.";
	cin.get(input, 10);
	cin.clear();
	cin.ignore(10000, '\n');

	if(strcmp(input, "y") == 0) {
	  delete *b;
	  b = media->erase(b);
	  return;
	}
      }
    }
 }

int main() {//main method, gets user input to look search delete or quit. 
  bool quit = false;//turned on when user wants to quit.
   vector<Media*> mediaVector;
   char input[10];//these store input from user
   char secondEntryInput[50];
   int thirdEntryInput;
   while(quit == false) {//loop while the user hasn't chosen to quit.
     cout << "would you like to add, search, delete, or quit? valid inputs are 'add', 'search', 'delete', or 'quit'." << endl;//get user input and then go do the function the user wants
     cin.get(input, 10);
     cin.clear();
     cin.ignore(10000, '\n');
     if((strcmp(input, "add")) == 0) {//add media
       ADD(&mediaVector);
     }
     else if((strcmp(input, "search")) == 0) {//ask user to look by title or year
       cout << "Search by year or title? enter 'year' or 'title'." << endl;
       cin.get(input, 10);
       cin.clear();
       cin.ignore(1000000, '\n');
       if(strcmp(input, "year") == 0) {
	   cout << "Enter year" << endl;
	   cin >> thirdEntryInput;
	   cin.clear();
	   cin.ignore(10000, '\n');
	   SEARCH(thirdEntryInput, &mediaVector);

       }
       else if(strcmp(input, "title") == 0) {
	   cout << "Enter title" << endl;
	   cin.get(secondEntryInput, 10);
	   cin.clear();
	   cin.ignore(10000, '\n');
	   SEARCH(secondEntryInput, &mediaVector);
       }
       else {
	 cout << "Invalid input." << endl;
       }
     }
     else if((strcmp(input, "delete")) == 0) {//ask user to delete by title or year
       cout << "Delete by year or title? Enter 'year' or 'title'." << endl;
       cin.get(input, 10);
       cin.clear();
       cin.ignore(1000000, '\n');
       if(strcmp(input, "year") == 0) {
	   cout << "Enter year." << endl;
	   cin >> thirdEntryInput;
	   cin.clear();
	   cin.ignore(10000, '\n');
	   DELETE(thirdEntryInput, &mediaVector);
	   
       }
       else if(strcmp(input, "title") == 0) {
	   cout << "Enter title." << endl;
	   cin.get(secondEntryInput, 10);
	   cin.clear();
	   cin.ignore(10000, '\n');
	   DELETE(secondEntryInput, &mediaVector);
       }
       else {
	 cout << "Invalid input." << endl;
       }       
     }
     else if((strcmp(input, "quit")) == 0) {//quit the program
       quit = true;
     }
     else {//invalid input
       cout << "Invalid input." << endl;
     }
   }
 }

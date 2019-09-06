#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
//Raymond Baartmans
//Guessing Game
//9/6/2019
int main()
{
  srand(time(NULL));//generates random number
  bool gameComplete = false;//used to know when to stop guessing loop
  int guesses = 0;//counts number of guesses
  int numToGuess = rand() % 101;//generate random number
  int input = 0;//holds the current guessed number
  while (!gameComplete)//this loop contains the process for a guess and loops until you guess the right number
    {
      cout << "Guess a number from 0 to 100:" << endl;
      bool validguess = false;
      while (!validguess)
	{
	  cin >> input; //get user input
	  if (cin.fail())
	    {
	      cout << "Invalid input. Try again" << endl;
	      cin.clear();
	      cin.ignore(1);
	    }
	  else
	    {
	      validguess = true;
	    }
	}
      guesses++;//Add one guess to the total
      if (input == numToGuess)//if the guess was correct
	{
	  cout << "You guessed it!" << endl;
	  gameComplete = true;
	}
      else if (input > numToGuess)//if the guess was too high
	{
	  cout << "Your guess was too high." << endl;
	}
      else if (input < numToGuess)//if the guess was too low
	{
	  cout << "Your guess was too low." << endl;
	}
      else//else, maybe if the guess was a letter or something.
	{
	  cout << "I don't think you guessed a number." << endl;
	}
    }
  cout << "Game over. You won in " << ++guesses << " guesses. Would you like to play again? Press 1 to play again, and any other button to exit." << endl;//Game over message will display after the loop, which stops looping when you guess the correct number
  cin >> input;//get user input for whether or not the user wants to replay
  if (input == 1)//is the input 1, if yes restart
    {
      main();//Start a new guessing game
    }

  return 0;
}

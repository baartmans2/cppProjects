#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
  srand(time(NULL));
  bool gameComplete = false;
  int guesses = 0;
  int numToGuess = rand() % 101;
  int input = 0;
  while (!gameComplete)
    {
      cout << "Guess a number from 0 to 100:" << endl;
      cin >> input;
      guesses++;
      if (input == numToGuess)
	{
	  cout << "You guessed it!" << endl;
	  gameComplete = true;
	}
      else if (input > numToGuess)
	{
	  cout << "Your guess was too high." << endl;
	}
      else if (input < numToGuess)
	{
	  cout << "Your guess was too low." << endl;
	}
      else
	{
	  cout << "I don't think you guessed a number." << endl;
	}
    }
  cout << "Game over. You won in " << ++guesses << " guesses. Would you like to play again? Press 1 to play again, and any other button to exit." << endl;
  cin >> input;
  if (input == 1)
    {
      main();
    }

  return 0;
}

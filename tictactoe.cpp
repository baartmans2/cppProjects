#include <iostream>
using namespace std;

//03 tictactoe
//raymond baartmans
//9/24/2019

void printDaBoard(char board [3][3]);//this method prints out the current board
int getRowOrColumn();//this method gets a number from input
char checkWin(char board [3][3]);//this method checks if there is a winner

int main()
{
  bool gameover = false;//if the game is over
  int turn = 1; int row; int column;//variables that store ints
  char input;//holds your input
  int xwins = 0; int owins = 0;//holds the number of wins for x and o
  
  
  char daBoard [3][3];//holds the tictactoe board
  cout << "tic tac toe time" << endl;

  for (int i = 0; i < 3; i++)//fill board with blanks
    {
      for (int j = 0; j < 3; j++)
	{
	  daBoard[i][j] = '_';
	}
    }

  printDaBoard(daBoard);//print it so the user can see

  while (!gameover)//loop it
    {
      cout << "Enter the row you want to make a move in. Top row is 1, bottom row is 3." << endl;
      row = getRowOrColumn();//get row
      if (row > 0)//if valid
	{
	  cout << "Enter the column you want to make a move in. Left column is 1, right column is three." << endl;
	  column = getRowOrColumn();//get column
	  if (column > 0)//if valid
	    {
	      row--; column--;//sub 1 so they work with the array
	      if (daBoard[row][column] == '_')
		{
	      
		  if (turn % 2 == 1)//if x's turn
		    {
		      daBoard[row][column] = 'x';
		    }
		  else if (turn % 2 == 0)//if o's turn
		    {
		      daBoard[row][column] = 'o';
		    }

		  // cout << checkWin(daBoard) << endl;
		  if (checkWin(daBoard) != 'n')//if there is a consistency in a row that isnt made up of _'s
		    {
		      //	      cout << "hello" << endl;
		      if (checkWin(daBoard) == 'x')//if the winner is x
			{
			  xwins++;
			}
		      else//its o
			{
			  owins++;
			}
		      
		   
		      cout << checkWin(daBoard) << " wins!" << endl;//print win msg
		      printDaBoard(daBoard);//print winning board
		      cout << "X wins: " << xwins << endl;//print out win counts. The spacing got really messed up here
						     cout << "O wins: " << owins << endl;

						     for (int i = 0; i < 3; i++)//clear board
						       {
							 for (int j = 0; j < 3; j++)
							   {
							     daBoard[i][j] = '_';
							   }
						       }
						     turn = 0;//reset vars
										    
		    }

		  turn++;
		  {
		    if (turn == 10)
		      {
			cout << "tie" << endl;
			for (int i = 0; i < 3; i++)
			  {
			    for (int j = 0; j < 3; j++)
			      {
				daBoard[i][j] = '_';
			      }
			  }
		      }
		  }
		  printDaBoard(daBoard);
		}
	      else//if someone moved here
		{
		  cout << "Someone already made a move there! Try again." << endl;
		}
	      
	    }
	}
    }
  
  return 0;
}

void printDaBoard(char board [3][3])//goes through board array and prints the values there
{
  int counter = 0;
  for (int i = 0; i < 3; i++)
    {
      cout << board[i][0] << " " << board[i][1] << " " << board[i][2] << endl;
    }
}

char checkWin (char board [3][3])//Goes through every possible win combo and returns the char who won. returns 'n' if no one has won yet
{
  if ((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]))
    {
      if (board[0][0] != '_')
	{
	  return board[0][0];
	}
    }
  if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]))
    {
      if (board[0][1] != '_')
	{
	  return board[0][1];
	}
    }
  if ((board[0][2] == board [1][2]) && (board[1][2] == board[2][2]))
    {
      if (board[0][2] != '_')
	{
	  return board[0][2];
	}
    }
  if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]))
    {
      if (board[0][0] != '_')
	{
	  return board[0][0];
	}
    }
  if ((board[1][0] == board[1][1]) && (board [1][1] == board[1][2]))
    {
      if (board[1][0] != '_')
	{
	  return board[1][0];
	}
    }
  if ((board [2][0] == board[2][1]) && (board[2][1] == board[2][2]))
    {
      if (board[2][0] != '_')
	{
	  return board[2][0];
	}
    }
  if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
    {
      if (board[0][0] != '_')
	{
	  return board[0][0];
	}
    }
  if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
    {
      if (board[0][2] != '_')
	{
	  return board[0][2];
	}
    }

  return 'n';
 
}

int getRowOrColumn()//used to convert user input for the row or column into a useable int
 {
   char input;
   cin >> input;
   if (input == '1')
     {
       return 1;
     }
   else if (input == '2')
     {
       return 2;
     }
   else if (input == '3')
     {
       return 3;
     }
   else
     {
       cout << "Invalid Input." << endl;
       return 0;
     }
 }

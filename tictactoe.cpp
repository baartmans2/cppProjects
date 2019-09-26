#include <iostream>
using namespace std;

//03 tictactoe
//raymond baartmans
//9/24/2019

void printDaBoard(char board [3][3]);
int getRowOrColumn();
char checkWin(char board [3][3]);

int main()
{
  bool gameover = false;
  int turn = 1; int row; int column;
  char input;
  int xwins = 0; int owins = 0;
  
  
  char daBoard [3][3];
  cout << "tic tac toe time" << endl;

  for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
	{
	  daBoard[i][j] = '_';
	}
    }

  printDaBoard(daBoard);

  while (!gameover)
    {
      cout << "Enter the row you want to make a move in. Top row is 1, bottom row is 3." << endl;
      row = getRowOrColumn();
      if (row > 0)
	{
	  cout << "Enter the column you want to make a move in. Left column is 1, right column is three." << endl;
	  column = getRowOrColumn();
	  if (column > 0)
	    {
	      row--; column--;
	      if (daBoard[row][column] == '_')
		{
	      
		  if (turn % 2 == 1)
		    {
		      daBoard[row][column] = 'x';
		    }
		  else if (turn % 2 == 0)
		    {
		      daBoard[row][column] = 'o';
		    }

		  // cout << checkWin(daBoard) << endl;
		  if (checkWin(daBoard) != 'n')
		    {
		      //	      cout << "hello" << endl;
		      if (checkWin(daBoard) == 'x')
			{
			  xwins++;
			}
		      else
			{
			  owins++;
			}
		      
		   
		      cout << checkWin(daBoard) << " wins!" << endl;
		      printDaBoard(daBoard);
		      cout << "X wins: " << xwins << endl;
						     cout << "O wins: " << owins << endl;

						     for (int i = 0; i < 3; i++)
						       {
							 for (int j = 0; j < 3; j++)
							   {
							     daBoard[i][j] = '_';
							   }
						       }
						     turn = 0;
										    
		    }

		  turn++;
		  printDaBoard(daBoard);
		}
	      else
		{
		  cout << "Someone already made a move there! Try again." << endl;
		}
	      
	    }
	}
    }
  
  return 0;
}

void printDaBoard(char board [3][3])
{
  int counter = 0;
  for (int i = 0; i < 3; i++)
    {
      cout << board[i][0] << " " << board[i][1] << " " << board[i][2] << endl;
    }
}

char checkWin (char board [3][3])
{
  if ((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]))
    {
      if (board[0][0] != '_')
	{
	  return board[0][0];
	}
    }
  else if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]))
    {
      if (board[0][1] != '_')
	{
	  return board[0][1];
	}
    }
  else if ((board[0][2] == board [1][2]) && (board[1][2] == board[2][2]))
    {
      if (board[0][2] != '_')
	{
	  return board[0][2];
	}
    }
  else if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]))
    {
      if (board[0][0] != '_')
	{
	  return board[0][0];
	}
    }
  else if ((board[1][0] == board[1][1]) && (board [1][1] == board[1][2]))
    {
      if (board[1][0] != '_')
	{
	  return board[1][0];
	}
    }
  else if ((board [2][0] == board[2][1]) && (board[2][1] == board[2][2]))
    {
      if (board[2][0] != '_')
	{
	  return board[2][0];
	}
    }
  else if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
    {
      if (board[0][0] != '_')
	{
	  return board[0][0];
	}
    }
  else if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
    {
      if (board[0][2] != '_')
	{
	  return board[0][2];
	}
    }
  else
    {
      return 'n';
    }
  return 'n';
 
}

 int getRowOrColumn()
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

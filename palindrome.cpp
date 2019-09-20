
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

//palindrome
//raymond baartmans
//9/18/2019

int main()
{
  bool palindrome = false;//whether the word is a palindrome
  char input [80];//array that stores orig input;
  char array2 [80];//stores chars w/o punctuation
  char array3 [80];//stores reversed chars
  int spot = 0;//the location of the terminating nullchar
  cout << "Enter in a bunch of characters - up to 80." << endl;
  cin.getline(input, 80);
  if (sizeof(input) == 0)//im lazy so i didnt bother deleting this since it will never execute
    {
      cout << "Enter something!";
    }
  else
    {
      for (int i = 0; i < 80; i++)//convert all to lower case
	{
	  if ((input[i] < 91) && (input[i] > 64))
	    {
	      input[i] = input[i] + 32;
	    }
	}
      
      int counter = 0; //used in compressing input
      for (int i = 0; i < 80; i++)
	{//read through the array and insert all non puncuation stuff into array2
	  if ( ( ( input[i] >= 97) && (input[i] <= 122) ) )//char values for normal characters
	    {
	      array2[counter] = input[i];
	      counter++;
	    }
	  else if (input[i] == '\0')//if we see the terminating null char, save that spot and quit the loop
	    {
	      i = 80;
	    }
	}
      spot = counter;
      counter = 0;
      for (int i = spot; i >= 0; i--)//move backwards from the spot and reverse the input
	{
	  if ( ((array2[i] >= 97) &&  (array2[i] <= 122)))
	    {
	      array3[counter] = array2[i];
	      counter++;
	    }
	}
      
      
      for (int i = 0; i <= spot; i++)//print out words so the person can see
	{
	  cout << array2[i] << endl;
	}
      for (int i = 0; i <= spot; i++)
	{
	  cout << array3[i] << endl;
	  }

      palindrome = true;//for this we start out with palindrome as true and if there is a difference in the normal and reversed word we set it false
      for (int i = 0; i <= spot; i++)
	{
	  if (array2[i] != array3[i])
	    {
	      palindrome = false;
	    }
	}
      //display whether the word is a palindrome or not
      if (palindrome)
	{
	  cout << "Palindrome" << endl;
	}
      else
	{
	  cout << "not palindrome" << endl;
	}
      
    }
    
  
}

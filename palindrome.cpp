
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
  char input [80];
  char array2 [80];
  char array3 [80];
  cout << "Enter in a bunch of characters - up to 80." << endl;
  cin >> input;
  if (sizeof(input) == 0)
    {
      cout << "Enter something!";
    }
  else
    {
      int counter = 0; 
      for (int i = 0; i < 80; i++)
	{
	  if (( input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z'))
	    {
	      array2[counter] = input[i];
	      counter++;
	    }
	  else if (input[i] == '\0')
	    {
	      i = 79;
	    }
	}
      counter = 0;
      for (int i = 79; i >= 0; i -= 1)
	{
	  if ( (array2[i] >= 'A' && array2[i] <= 'Z') || (array2[i] >= 'a' && array2[i] <= 'z') )
	    {
	      array3[counter] = array2[i];
	      counter++;
	    }
	}
      cout << array2[0] << endl;
      cout << array3[0] << endl;
      cout << array3[1] << endl;
      cout << array3[2] << endl;
      cout << array3[3] << endl;
      
      if (array2 == array3)
	{
	  cout << "Palindrome" << endl;
	}
      else
	{
	  cout << "not palindrome" << endl;
	}
      
    }

  
}

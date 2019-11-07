#include <iostream>
#include <cstring>

using namespace std;

class Media
{
 public:
  int getType();
  int* getYear();
  char* getTitle();
 protected:
  int* year;
  char* title;
}

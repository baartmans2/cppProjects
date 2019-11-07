#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media
{
public:
  Movie();
    char* getDirector();
  int* getDuration();
  float* getRating();
protected:
  char* director;
  int* duration;
  float* rating;
}

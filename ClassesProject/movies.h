#ifndef MOVIE_H
#define MOVIE_H

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
  virtual int getType();
protected:
  char director[50];
  int duration;
  float rating;
};

#endif

#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class VideoGames : public Media
{
 public:
  VideoGames();
  char* getMaker();
  virtual int getType();
  float* getRating();
 protected:
  char maker[50];
  float rating;
};

#endif

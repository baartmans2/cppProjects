#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media
{
 public:
  Music();
  char* getArtist();
  char* getPublisher();
  virtual int getType();
  int* getLength();
 protected:
  char artist[50];
  char publisher[50];
  int length;
};

#endif

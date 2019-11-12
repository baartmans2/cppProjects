#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class Media
{
 public:
  Media();
  virtual int getType();
  int* getYear();
  char* getTitle();
 protected:
  int year;
  char title[50];
};

#endif

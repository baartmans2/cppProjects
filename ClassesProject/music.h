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
  int* getLength();
 protected:
  char* artist;
  char* publisher;
  int* length;
}

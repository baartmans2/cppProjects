#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class VideoGames : public Media
{
 public:
  VideoGames();
  char* getMaker();
  float* getRating();
 protected:
  char* maker;
  float* rating;
}

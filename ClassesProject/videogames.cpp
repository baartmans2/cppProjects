#include <iostream>
#include <cstring>
#include "media.h"
#include "videogames.h"

using namespace std;

VideoGames::VideoGames()
{

}
int VideoGames::getType()
{
  return 1;
}
char* VideoGames::getMaker()
{
  return maker;
}
float* VideoGames::getRating()
{
  return &rating;
}

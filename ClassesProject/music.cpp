#include <iostream>
#include <cstring>
#include "media.h"
#include "music.h"

using namespace std;

Music::Music()
{

}
int Music::getType()
{
  return 2;
}
char* Music::getArtist()
{
  return artist;
}
char* Music::getPublisher()
{
  return publisher;
}
int* Music::getLength()
{
  return &length;
}

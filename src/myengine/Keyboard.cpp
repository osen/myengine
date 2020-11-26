#include "Keyboard.h"

namespace myengine
{

bool Keyboard::getKey(int key)
{
  for(size_t ki = 0; ki < keys.size(); ki++)
  {
    if(keys.at(ki) == key)
    {
      return true;
    }
  }

  return false;
}

}


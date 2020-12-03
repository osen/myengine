#include <vector>

#ifdef USE_SDL
  #define KEY_A 'a'
  #define KEY_UP SDLK_UP
#else 
  #define KEY_A 223
  #define KEY_UP GLUT_UPARROW
#endif

namespace myengine
{

struct Core;

struct Keyboard
{
  bool getKey(int key);

private:
  friend struct myengine::Core;

  std::vector<int> keys;
  std::vector<int> downKeys;
  std::vector<int> upKeys;

};

}

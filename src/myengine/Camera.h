#include "Component.h"

#include <rend/rend.h>

namespace myengine
{

struct Camera : public Component
{
  void onInitialize();
  //void onDestroy();

  rend::mat4 getView();
};

}


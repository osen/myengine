#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

namespace myengine
{

struct Component
{
  void tick();
  virtual void onTick();

  void render();
  virtual void onRender();

};

}

#endif

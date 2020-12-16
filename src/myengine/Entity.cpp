#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace myengine
{

void Entity::tick()
{
  for(size_t ci = 0; ci < components.size(); ci++)
  {
    components.at(ci)->tick();
  }
}

void Entity::render()
{
  for(size_t ci = 0; ci < components.size(); ci++)
  {
    components.at(ci)->render();
  }
}

std::shared_ptr<Core> Entity::getCore()
{
  return core.lock();
}

std::shared_ptr<Transform> Entity::getTransform()
{
  return getComponent<Transform>();
}

void Entity::destroy()
{
  if(alive)
  {
    alive = false;

    for(size_t ci = 0; ci < components.size(); ci++)
    {
      components.at(ci)->destroy();
    }
  }
}

}


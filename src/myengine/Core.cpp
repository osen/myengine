#include "Core.h"
#include "Entity.h"

namespace myengine
{

std::shared_ptr<Core> Core::initialize()
{
  std::shared_ptr<Core> rtn = std::make_shared<Core>();

  return rtn;
}

std::shared_ptr<Entity> Core::addEntity()
{
  std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

  entities.push_back(rtn);

  return rtn;
}

void Core::start()
{
  for(size_t ei = 0; ei < entities.size(); ei++)
  {
    entities.at(ei)->tick();
  }
}

}


#include "Component.h"
#include "Entity.h"

namespace myengine
{

void Component::tick()
{
  onTick();
}

void Component::render()
{
  onRender();
}

void Component::onInitialize() { }
void Component::onTick() { }
void Component::onRender() { }

std::shared_ptr<Entity> Component::getEntity()
{
  return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
  return getEntity()->getCore();
}

}


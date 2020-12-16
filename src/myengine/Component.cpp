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

void Component::destroy()
{
  onDestroy();
}

void Component::onInitialize() { }
void Component::onTick() { }
void Component::onRender() { }
void Component::onDestroy() { }

std::shared_ptr<Entity> Component::getEntity()
{
  return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
  return getEntity()->getCore();
}

std::shared_ptr<Transform> Component::getTransform()
{
  return getEntity()->getTransform();
}

}

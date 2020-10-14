#include "Component.h"

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

void Component::onTick() { }
void Component::onRender() { }

}


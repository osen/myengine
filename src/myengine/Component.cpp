#include "Component.h"

namespace myengine
{

void Component::tick()
{
  onTick();
}

void Component::onTick() { }

}


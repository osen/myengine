#include "Transform.h"

namespace myengine
{

void Transform::onInitialize()
{
  scale = rend::vec3(1, 1, 1);
}

rend::mat4 Transform::getModel()
{
  rend::mat4 rtn(1.0f);

  rtn = rend::translate(rtn, position);
  rtn = rend::rotate(rtn, rend::radians(rotation.x), rend::vec3(1, 0, 0));
  rtn = rend::rotate(rtn, rend::radians(rotation.y), rend::vec3(0, 1, 0));
  rtn = rend::rotate(rtn, rend::radians(rotation.z), rend::vec3(0, 0, 1));
  rtn = rend::scale(rtn, scale);

  return rtn;
}

void Transform::setPosition(rend::vec3 position)
{
  this->position = position;
}

void Transform::rotate(float x, float y, float z)
{
  this->rotation += rend::vec3(x, y, z);
}

void Transform::translate(float x, float y, float z)
{
  rend::vec4 fwd = getModel() * rend::vec4(x, y, z, 0);

  position += rend::vec3(fwd);
}

}


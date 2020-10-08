#include "Component.h"

#include <vector>
#include <memory>

namespace myengine
{

struct Component;

struct Entity
{

  ~Entity();

  template <typename T>
  std::shared_ptr<T> addComponent()
  {
    std::shared_ptr<T> rtn = std::make_shared<T>();

    components.push_back(rtn);

    return rtn;
  }

  void tick();

private:
  std::vector<std::shared_ptr<Component>> components;

};

}

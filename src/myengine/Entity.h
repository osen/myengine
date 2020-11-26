#include "Exception.h"

#include <vector>
#include <memory>

namespace myengine
{

struct Component;
struct Core;
struct Exception;
struct Transform;

struct Entity
{
  friend struct ::myengine::Core;

  template <typename T>
  std::shared_ptr<T> addComponent()
  {
    std::shared_ptr<T> rtn = std::make_shared<T>();
    rtn->entity = self;

    components.push_back(rtn);

    rtn->onInitialize();

    return rtn;
  }

  template <typename T, typename ... Args>
  std::shared_ptr<T> addComponent(Args&&... args)
  {
    std::shared_ptr<T> rtn = std::make_shared<T>();
    rtn->entity = self;

    components.push_back(rtn);

    rtn->onInitialize(std::forward<Args>(args)...);

    return rtn;
  }

  template <typename T>
  std::shared_ptr<T> getComponent()
  {
    for(size_t i = 0; i < components.size(); i++)
    {
      std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(components.at(i));

      if(!rtn) continue;

      return rtn;
    }

    throw Exception("Entity does not contain requested type");
  }

  void tick();
  void render();

  std::shared_ptr<Core> getCore();
  std::shared_ptr<Transform> getTransform();

private:
  std::vector<std::shared_ptr<Component>> components;
  std::weak_ptr<Core> core;
  std::weak_ptr<Entity> self;

};

}

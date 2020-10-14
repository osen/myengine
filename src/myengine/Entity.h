#include <vector>
#include <memory>

namespace myengine
{

struct Component;
struct Core;

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

  void tick();
  void render();

  std::shared_ptr<Core> getCore();

private:
  std::vector<std::shared_ptr<Component>> components;
  std::weak_ptr<Core> core;
  std::weak_ptr<Entity> self;

};

}

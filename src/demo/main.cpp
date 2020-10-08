#include <myengine/myengine.h>

struct Renderer : public Component
{
  int dummy;
};

int main()
{
  std::shared_ptr<Core> core = Core::initialize();

  std::shared_ptr<Entity> pe = core->addEntity();

  std::shared_ptr<Renderer> pc = pe->addComponent<Renderer>();

  return 0;
}

#include <myengine/myengine.h>

#include <iostream>

struct Renderer : public Component
{
  int health;

  void onTick()
  {
    std::cout << "Hello Tick" << std::endl;

    // if(getEntity()->getCore()->getKeyboard()->isKeyDown(KEY))
    // if(getKeyboard()->isKeyDown(KEY))
     // move player
  }
};

struct LogCutter : public Component
{
  int dummy;
};

#define shared std::shared_ptr

int main()
{
  std::shared_ptr<Core> core = Core::initialize();
  std::shared_ptr<Entity> pe = core->addEntity();
  std::shared_ptr<Renderer> pc = pe->addComponent<Renderer>();

  //std::shared_ptr<Renderer> pc2 = pe->getComponent<Renderer>();
  //shared<LogCutter> lc = std::dynamic_pointer_cast<LogCutter>(pc);
  //std::cout << lc << std::endl;

  core->start();

  return 0;
}

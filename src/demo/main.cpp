#include <myengine/myengine.h>

#include <iostream>

struct Player : public Component
{
  void onInitialize(int team, int type, std::string name)
  {
    std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();
  }

  void onTick()
  {
    if(getCore()->getKeyboard()->getKey('d'))
    {
      // Move right
      std::cout << "Moving right" << std::endl;
      getTransform()->translate(0.1f, 0, 0);
    }

    if(getCore()->getKeyboard()->getKey('e'))
    {
      getTransform()->rotate(0, 0.1f, 0);
    }
  }
};

int main()
{
  std::shared_ptr<Core> core = Core::initialize();

  std::shared_ptr<Entity> pe = core->addEntity();
  pe->getTransform()->setPosition(rend::vec3(0, 0, -10));
  std::shared_ptr<Player> p = pe->addComponent<Player>(1, 2, "Karsten");

  std::shared_ptr<Entity> pe2 = core->addEntity();
  std::shared_ptr<Renderer> r2 = pe2->addComponent<Renderer>();
  r2->getTransform()->setPosition(rend::vec3(2, 1, -5));

  core->start();

  return 0;
}

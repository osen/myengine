#include <myengine/myengine.h>

struct Player : public Component
{
  void onInitialize(int team, int type, std::string name)
  {
    std::shared_ptr<Renderer> r = getEntity()->addComponent<Renderer>();

    std::shared_ptr<Model> cm = getCore()->getResources()->
      load<Model>("models/curuthers/curuthers");

    r->setModel(cm);
  }

  //void onGui()
  //{
  //  getCore()->getGui()->draw(rt, 0, 0, 100, 100);
  //}
};

struct Controller : public Component
{
  void onTick()
  {
    if(getCore()->getKeyboard()->getKey('w'))
    {
      getTransform()->translate(0, 0, 0.1f);
    }
    else if(getCore()->getKeyboard()->getKey('s'))
    {
      getTransform()->translate(0, 0, -0.1f);
    }

    if(getCore()->getKeyboard()->getKey('e'))
    {
      getTransform()->rotate(0, 0.1f, 0);
    }
    else if(getCore()->getKeyboard()->getKey('q'))
    {
      getTransform()->rotate(0, -0.1f, 0);
    }
  }
};

int main()
{
  std::shared_ptr<Core> core = Core::initialize();

  /*
   * Add test player object
   */
  std::shared_ptr<Entity> pe = core->addEntity();
  pe->getTransform()->setPosition(rend::vec3(0, 0, -10));
  std::shared_ptr<Player> p = pe->addComponent<Player>(1, 2, "Karsten");

  /*
   * Add sample object to collide against
   */
  std::shared_ptr<Entity> pe2 = core->addEntity();
  std::shared_ptr<Renderer> r2 = pe2->addComponent<Renderer>();
  r2->getTransform()->setPosition(rend::vec3(2, 1, -5));

  std::shared_ptr<Entity> camera = core->addEntity();
  camera->addComponent<Camera>();
  camera->addComponent<Controller>();

  std::shared_ptr<Entity> c2 = core->addEntity();
  c2->getTransform()->setPosition(rend::vec3(0, 20, 0));
  c2->getTransform()->rotate(-90, 0, 0);
  std::shared_ptr<Camera> mc = c2->addComponent<Camera>();
  mc->addRenderTexture();

  core->start();

  return 0;
}

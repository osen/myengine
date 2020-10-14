#include <SDL2/SDL.h>
#include <rend/rend.h>

#include <memory>
#include <vector>

namespace myengine
{

struct Renderer;
struct Entity;

struct Core
{
  friend struct myengine::Renderer;

  static std::shared_ptr<Core> initialize();

  std::shared_ptr<Entity> addEntity();

  void start();

private:
  std::vector<std::shared_ptr<Entity>> entities;
  std::weak_ptr<Core> self;
  SDL_Window* window;
  SDL_GLContext glContext;
  std::shared_ptr<rend::Context> context;

};

}

#include "Component.h"

#include <rend/rend.h>

#include <memory>

namespace myengine
{

struct Renderer : public Component
{
  void onInitialize();
  void onRender();

private:
  std::shared_ptr<rend::Shader> shader;
  std::shared_ptr<rend::Mesh> shape;
  // std::shared_ptr<Texture> texture;

};

}

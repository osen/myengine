#include "Component.h"

#include <rend/rend.h>

namespace myengine
{

struct Camera : public Component
{
  void onInitialize();
  //void onDestroy();

  rend::mat4 getView();
  std::shared_ptr<rend::RenderTexture> getRenderTexture();

  std::shared_ptr<rend::RenderTexture> addRenderTexture();

private:
  std::shared_ptr<rend::RenderTexture> renderTexture;

};

}


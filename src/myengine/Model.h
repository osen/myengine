#include "Resource.h"
#include "Exception.h"

#include <rend/rend.h>

#include <string>
#include <memory>

namespace myengine
{

struct Model : public Resource
{
  void onLoad();

private:
  std::shared_ptr<rend::Mesh> mesh;

};

}


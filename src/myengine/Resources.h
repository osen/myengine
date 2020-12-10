#include "Resource.h"

#include <vector>
#include <memory>
#include <string>

namespace myengine
{

struct Core;

struct Resources
{
  template <typename T>
  std::shared_ptr<T> load(const std::string& path)
  {
    std::shared_ptr<T> rtn;

    for(size_t i = 0; i < resources.size(); i++)
    {
      if(path == resources.at(i)->getPath())
      {
        rtn = std::dynamic_pointer_cast<T>(resources.at(i));
        if(!rtn) continue;

        return rtn;
      }
    }

    rtn = std::make_shared<T>();
    rtn->core = core;
    rtn->path = path;
    rtn->onLoad();
    resources.push_back(rtn);

    return rtn;
  }

private:
  friend struct myengine::Core;

  std::vector<std::shared_ptr<Resource> > resources;
  std::weak_ptr<Core> core;
};

}


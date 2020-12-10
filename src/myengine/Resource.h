#ifndef MYENGINE_RESOURCE_H
#define MYENGINE_RESOURCE_H

#include <string>
#include <memory>

namespace myengine
{

struct Core;
struct Resources;

struct Resource
{
  virtual ~Resource();
  virtual void onLoad();
  //virtual void onCreate();

  std::string getPath();
  std::shared_ptr<Core> getCore();

private:
  friend struct myengine::Resources;

  std::string path;
  std::weak_ptr<Core> core;

};

}

#endif

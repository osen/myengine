#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>

namespace myengine
{

struct Entity;
struct Core;
struct Transform;

/**
 * \brief Provides the base class that any classes added to Entity should inherit.
 */
struct Component
{
  friend struct myengine::Entity;

  virtual void onInitialize();

  /**
   * \brief Propagates tick event to the derived type.
   *
   * More detail describing what the function does.
   */
  void tick();
  virtual void onTick();

  void render();
  virtual void onRender();

  void destroy();
  virtual void onDestroy();

  std::shared_ptr<Entity> getEntity();
  std::shared_ptr<Core> getCore();
  std::shared_ptr<Transform> getTransform();

private:
  /// \brief The entity that the Component is attached to.
  std::weak_ptr<Entity> entity;
};

}

#endif

#include "Renderer.h"
#include "Core.h"
#include "Transform.h"
#include "Entity.h"
#include "Exception.h"
#include "Camera.h"
#include "Model.h"

#include <fstream>
#include <string>
#include <iostream>

namespace myengine
{

void Renderer::onInitialize()
{
  const char* src =
    "\n#ifdef VERTEX\n                       " \
    "attribute vec3 a_Position;              " \
    "attribute vec2 a_TexCoord;              " \
    "attribute vec3 a_Normal;                " \
    "uniform mat4 u_Projection;              " \
    "uniform mat4 u_View;                    " \
    "uniform mat4 u_Model;                   " \
    "varying vec2 v_TexCoord;                " \
    "                                        " \
    "void main()                             " \
    "{                                       " \
    "  gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1); " \
    "  v_TexCoord = a_TexCoord;              " \
    "  if(a_Normal.x == 9) gl_Position.x = 7;" \
    "}                                       " \
    "                                        " \
    "\n#endif\n                              " \
    "\n#ifdef FRAGMENT\n                     " \
    "uniform sampler2D u_Texture;            " \
    "varying vec2 v_TexCoord;                " \
    "                                        " \
    "void main()                             " \
    "{                                       " \
    "  gl_FragColor = vec4(v_TexCoord, 0, 1);" \
    "}                                       " \
    "                                        " \
    "\n#endif\n                              ";

  shader = getCore()->context->createShader();
  shader->parse(src);

  //model = getResources()->load<Model>("internal/placeholder");
}

void Renderer::onRender()
{
  if(!model) return;

  shader->setMesh(model->mesh);

  shader->setUniform("u_Projection", rend::perspective(rend::radians(45.0f),
    1.0f, 0.1f, 100.0f));

  shader->setUniform("u_View", getCore()->getCamera()->getView());
  shader->setUniform("u_Model", getEntity()->getTransform()->getModel());

  //shader->setSampler("u_Texture", texture->internal);

  std::shared_ptr<Camera> c = getCore()->getCamera();

  // iterate model parts
  //   set shader texture = part->texture
  //   render

  if(c->getRenderTexture())
  {
    shader->render(c->getRenderTexture());
  }
  else
  {
    shader->render();
  }
}

void Renderer::setModel(std::shared_ptr<Model> model)
{
  this->model = model;
}

}


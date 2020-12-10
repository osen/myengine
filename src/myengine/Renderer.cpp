#include "Renderer.h"
#include "Core.h"
#include "Transform.h"
#include "Entity.h"
#include "Exception.h"
#include "Camera.h"

#include <fstream>
#include <string>

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

  shape = getCore()->context->createMesh();
  std::ifstream file("models/curuthers/curuthers.obj");

  if(!file.is_open())
  {
    throw Exception("Failed to open model file");
  }

  std::string content;
  std::string line;

  while(!file.eof())
  {
    getline(file, line);
    content += line + "\n";
  }

  shape->parse(content);
}

void Renderer::onRender()
{
  shader->setMesh(shape);

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

}


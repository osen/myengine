cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

set(COMP "${CMAKE_CXX_COMPILER_ID}")
set(PLATFORM "${CMAKE_SYSTEM_NAME}")
set(ARCH "${CMAKE_SYSTEM_PROCESSOR}")
message("${COMP}-${PLATFORM}-${ARCH}")

include_directories(
  src
  ${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/include
)

link_directories(
  ${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/lib
)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if(MSVC OR MINGW)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_library(myengine
  src/myengine/Core.cpp
  src/myengine/Entity.cpp
  src/myengine/Component.cpp

  src/myengine/Core.h
  src/myengine/Entity.h
  src/myengine/Component.h
)
target_link_libraries(myengine rend)

add_executable(demo
  src/demo/main.cpp
)
target_link_libraries(demo myengine)

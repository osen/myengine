cmake_minimum_required(VERSION 2.6)
project(MYENGINE)

set(COMP "${CMAKE_CXX_COMPILER_ID}")
set(PLATFORM "${CMAKE_SYSTEM_NAME}")
set(ARCH "${CMAKE_SYSTEM_PROCESSOR}")
message("${COMP}-${PLATFORM}-${ARCH}")

add_definitions(-DSDL_MAIN_HANDLED)

include_directories(
  src
  ${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/include
)

link_directories(
  ${PROJECT_SOURCE_DIR}/contrib/${COMP}-${PLATFORM}-${ARCH}/lib
)

if(MINGW)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s -static")
  add_definitions(-DGLEW_STATIC)
  set(STATIC_LIBS imm32 iconv winmm ole32 gdi32 oleaut32 version)
endif()

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
  src/myengine/Exception.cpp
  src/myengine/Renderer.cpp

  src/myengine/Core.h
  src/myengine/Entity.h
  src/myengine/Component.h
  src/myengine/Exception.h
  src/myengine/Renderer.h
)
target_link_libraries(myengine rend SDL2 ${STATIC_LIBS})

add_executable(demo
  src/demo/main.cpp
)
target_link_libraries(demo myengine)

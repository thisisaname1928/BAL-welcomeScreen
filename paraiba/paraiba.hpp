#pragma once

#include "glad/glad/glad.h"
#include "scene/scene.hpp"
#include <GLFW/glfw3.h>
#include <string>

const std::string PARAIBA_VERSION_STRING = "ParaibaInDev";
const int PARAIBA_VERSION_INT = -1;
const bool PARAIBA_DEBUG = true;
#define DEBUG_MACRO

namespace Paraiba {

class Scene;

class Paraiba {
public:
  Paraiba(int width, int height, std::string title);
  void setScene(Scene &scene);
  ~Paraiba();

private:
  GLFWwindow *window;
  int width, height;
  Scene *currentScene;
};
} // namespace Paraiba
#pragma once
#include "../paraiba.hpp"
#include <GLFW/glfw3.h>

namespace Paraiba {

class Paraiba;

class Scene {
public:
  virtual void initScene(Paraiba *ptr);
  virtual ~Scene();
  virtual void onDraw();
  virtual void prepareScene();
  virtual void keyCallback(GLFWwindow *w, int key, int scancode, int action,
                           int mods);
  static void keyCallbackWrapper(GLFWwindow *w, int key, int scancode,
                                 int action, int mods);

private:
  inline static Scene *instance = nullptr;
  Paraiba *paraiba;
};
} // namespace Paraiba
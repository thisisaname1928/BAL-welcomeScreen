#include "scene.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

void Paraiba::Scene::initScene(Paraiba *ptr) {
  if (ptr == nullptr)
    throw std::runtime_error(
        "Paraiba::Scene::initScene::ERR_INIT_WITH_NULLPTR");

  paraiba = ptr;
  instance = this;
}

Paraiba::Scene::~Scene() {}

void Paraiba::Scene::onDraw() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Paraiba::Scene::keyCallback(GLFWwindow *w, int key, int scancode,
                                 int action, int mods) {
  std::cout << "KEY PRESSED\n";
}

// static wrapper for keyCallback
void Paraiba::Scene::keyCallbackWrapper(GLFWwindow *w, int key, int scancode,
                                        int action, int mods) {
  if (instance != nullptr)
    instance->keyCallback(w, key, scancode, action, mods);
}

void Paraiba::Scene::prepareScene() {}
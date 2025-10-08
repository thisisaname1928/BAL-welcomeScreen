
#include "paraiba.hpp"
#include "glad/glad/glad.h"
#include "paraiba/graphicsObject/base/baseGOBJ.hpp"
#include "paraiba/graphicsObject/vertex.hpp"
#include "shader/shader.hpp"
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <utils/utils.hpp>

Paraiba::Paraiba::Paraiba(int width, int height, std::string title)
    : width(width), height(height) {

  if (!glfwInit()) {
    throw std::runtime_error("Paraiba::ERR_GLFW_INIT_FAILED");
  }

  window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (window == nullptr)
    throw std::runtime_error("Paraiba::ERR_GLFW_CREATE_WINDOW_FAILED");

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    throw std::runtime_error("Paraiba::ERR_GLAD_LOAD_PROC_FAILED");

  // test here
  Shader *ss;
  Shader *s1;

  ss = new Shader(readFileContent("./assets/shader/test.vs"), GL_VERTEX_SHADER);
  s1 = new Shader(readFileContent("./assets/shader/test.fs"),
                  GL_FRAGMENT_SHADER);

  ShaderProgram prog;
  prog.attachShader(*ss);
  prog.attachShader(*s1);
  prog.link();

  Scene s;
  setScene(s);

  int angle = 0;

  while (!glfwWindowShouldClose(window)) {
    // currentScene->onDraw();
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    angle += 10;
    if (angle == 360)
      angle = 0;

    BasicGraphicsObject obj(prog);
    obj.addVertex(
        {.x = static_cast<float>(1 * std::cos((angle / 180.0) * 3.14)),
         .y = static_cast<float>(1 * std::sin((angle / 180.0) * 3.14)),
         .z = 0});
    obj.addVertex(
        {.x = static_cast<float>(0 * std::cos((angle / 180.0) * 3.14)),
         .y = 0,
         .z = 0});
    obj.addVertex(
        {.x = static_cast<float>(1 * std::cos((angle / 180.0) * 3.14)),
         .y = 0,
         .z = 0});
    obj.prepare();
    obj.draw();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }
}

Paraiba::Paraiba::~Paraiba() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

void Paraiba::Paraiba::setScene(Scene &scene) {
  currentScene = &scene;
  scene.initScene(this);

  glfwSetKeyCallback(window, scene.keyCallbackWrapper);
}
#pragma once
#include "../vertex.hpp"
#include "paraiba/shader/shader.hpp"
#include <cstdint>
#include <vector>

namespace Paraiba {
class BasicGraphicsObject {
public:
  void addVertex(Vertex v);
  // for preparing buffer, texture, ...
  void prepare();
  // call in drawing loop
  void draw();
  ShaderProgram &shaderProgram;
  BasicGraphicsObject(ShaderProgram &shaderProgram);

private:
  std::vector<Vertex> vertices;
  uint32_t VBO, VAO;
};
} // namespace Paraiba
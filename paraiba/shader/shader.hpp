#pragma once

#include <cstdint>
#include <string>
namespace Paraiba {
class Shader {
public:
  Shader(std::string source, uint32_t type);
  char *getLog();
  uint32_t getShaderID();
  ~Shader();

private:
  uint32_t shader;
  char log[512];
};

class ShaderProgram {
public:
  ShaderProgram();
  void attachShader(Shader &shader);
  bool link();
  void use();
  bool isProgramLinked();

private:
  uint32_t shaderProgram;
  bool isLinked;
};
} // namespace Paraiba
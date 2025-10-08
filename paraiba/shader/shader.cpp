#include "shader.hpp"
#include "paraiba/paraiba.hpp"
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <paraiba/glad/glad/glad.h>
#include <stdexcept>

Paraiba::Shader::Shader(std::string source, uint32_t type) {
  shader = glCreateShader(type);

  const char *src = source.c_str();

  glShaderSource(shader, 1, &src, NULL);
  glCompileShader(shader);

  // check compile status
  int status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
  glGetShaderInfoLog(shader, 512, NULL, log);

  if (!status) {
    if (PARAIBA_DEBUG)
      std::cout << log << "\n";
    throw std::runtime_error("PARAIBA::ERR_SHADER_COMPILE_FAILED");
  }
}

char *Paraiba::Shader::getLog() { return log; }
uint32_t Paraiba::Shader::getShaderID() { return shader; }
Paraiba::Shader::~Shader() { glDeleteShader(shader); }

Paraiba::ShaderProgram::ShaderProgram() {
  isLinked = false;
  shaderProgram = glCreateProgram();
}

void Paraiba::ShaderProgram::attachShader(Shader &shader) {
  glAttachShader(shaderProgram, shader.getShaderID());
}

bool Paraiba::ShaderProgram::link() {
  isLinked = true;

  glLinkProgram(shaderProgram);

  int status;
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);

#ifdef DEBUG_MACRO
  if (!status) {
    char log[512];
    glGetProgramInfoLog(shaderProgram, 512, NULL, log);

    std::cout << "PARAIBA::PROGRAM_LINK_FAILED\n" << log << "\n";
  }
#endif

  return status;
}

bool Paraiba::ShaderProgram::isProgramLinked() { return isLinked; }
void Paraiba::ShaderProgram::use() {
  if (isLinked) {
    glUseProgram(shaderProgram);
  }

#ifdef DEBUG_MACRO
  if (!isLinked) {
    std::cout << "[WARN]: Using shader that hasn't linked yet!\n";
  }
#endif
}
#include "baseGOBJ.hpp"
#include "../../glad/glad/glad.h"
#include "paraiba/graphicsObject/vertex.hpp"

void Paraiba::BasicGraphicsObject::addVertex(Vertex v) {
  vertices.push_back(v);
}

Paraiba::BasicGraphicsObject::BasicGraphicsObject(ShaderProgram &shaderProgram)
    : shaderProgram(shaderProgram) {
  // init buffer
  glGenBuffers(1, &VBO);
  glGenVertexArrays(1, &VAO);
}

void Paraiba::BasicGraphicsObject::prepare() {
  // load buffer data
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Paraiba::Vertex) * vertices.size(),
               vertices.data(), GL_STATIC_DRAW);
  // setup VAO
  glBindVertexArray(VAO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
  glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(Vertex),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
}

void Paraiba::BasicGraphicsObject::draw() {
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBindVertexArray(VAO);
  shaderProgram.use();

  glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
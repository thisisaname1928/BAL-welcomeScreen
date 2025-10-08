#pragma once

#include <cstdint>
namespace Paraiba {
typedef struct __attribute__((packed)) {
  float x, y, z;
  uint8_t r, g, b, a;
  float u, v;
} Vertex;
} // namespace Paraiba
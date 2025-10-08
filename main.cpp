#include "paraiba/glad/glad/glad.h"
#include "paraiba/paraiba.hpp"
#include "paraiba/shader/shader.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <utils/utils.hpp>
int main() {
  srand(static_cast<unsigned int>(time(0)));

  try {
    Paraiba::Paraiba engine(600, 400, "SUS");
  } catch (std::runtime_error e) {
    std::cout << e.what() << "\n";
  }
  return 0;
}
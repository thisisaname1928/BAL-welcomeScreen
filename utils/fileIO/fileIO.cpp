#include <fstream>
#include <string>

std::string readFileContent(std::string source) {
  std::ifstream ifs(source);
  std::string content((std::istreambuf_iterator<char>(ifs)),
                      (std::istreambuf_iterator<char>()));

  return content;
}
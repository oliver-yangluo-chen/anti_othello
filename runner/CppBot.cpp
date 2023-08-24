#include <iostream>
#include <string>

int main() {
  std::string bw;
  std::getline(std::cin, bw);

  std::cout << "ok" << std::endl;

  std::string line;
  while (line != "done" && std::cin) {
    std::getline(std::cin, line);

    if (line == "get move") {
      std::cout << "d4" << std::endl;
    } else {
      // ...
    }
  }

  return 0;
}
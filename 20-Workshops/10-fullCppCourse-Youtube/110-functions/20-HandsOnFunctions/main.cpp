#include <iostream>

// function declaration (header, prototype)
void enter_bar(unsigned int age);

int main() {
  enter_bar(28);
  return 0;
}

// function definition or implementation
void enter_bar(unsigned int age) {
  if (age > 18) {
    std::cout << "You're in!" << std::endl;
  } else {
    std::cout << "Sorry..." << std::endl;
  }
}
#include <iostream>

int main() {

  std::cout << "< Character array manipulation >" << std::endl;
  std::cout << std::endl;

  std::cout << "std::isalnum : " << std::endl;
  // check if a character is an alhpanumeric number
  std::cout << "C is alphanumeric : " << std::isalnum('C') << std::endl;
  std::cout << "^ is alphanumeric : " << std::isalnum('^') << std::endl;

  // can use this as a test condition
  char input_char{'*'};
  if (std::isalnum(input_char)) {
    std::cout << input_char << " is alphanumeric." << std::endl;
  } else {
    std::cout << input_char << " is not alphanumeric." << std::endl;
  }
  return 0;
}
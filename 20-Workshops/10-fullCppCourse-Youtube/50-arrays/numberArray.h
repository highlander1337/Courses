#include <iostream>

int scores[10];

void array10Int() {
  for (size_t i{0}; i < 10; ++i) {
    std::cout << "Enter one number : " << std::endl;
    std::cin >> scores[i];
  }

  /*
    old fashioned way to loop in an array (before c++17)
  */
  size_t count{sizeof(scores) / sizeof(scores[0])}; // 40 bytes / 4 bytes = 10

  // cout << "sizeof(scores) : " << sizeof(scores) << "bytes" << endl;
  // cout << "sizeof(scores[0]) : " << sizeof(scores[0]) << "byte" << endl;

  for (size_t i{0}; i < count; i++) {
    std::cout << "Scores[" << i << "] is equal to " << scores[i] << std::endl;
  }

  /*
    intermediate way to loop in an array after c++17
  */
  int __count{std::size(scores)};
  for (size_t i{0}; i < __count; i++) {
    std::cout << "Scores[" << i << "] is equal to " << scores[i] << std::endl;
  }

  /*
    advanced way to loop in an array
  */

  auto it = 0;
  for (auto score : scores) {
    std::cout << "Scores[" << it << "] is equal to " << score << std::endl;
    ++it;
  }
}
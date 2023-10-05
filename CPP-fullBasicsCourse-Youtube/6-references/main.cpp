#include <iostream>
int main() {
  // two different var names, same value and reference
  int myIntVar{4};
  int &myIntVarReference{myIntVar};

  std::cout << "myIntVar : " << myIntVar << std::endl;
  std::cout << "myIntVarReference : " << myIntVarReference << std::endl;

  std::cout << "myIntVar : " << &myIntVar << std::endl;
  std::cout << "myIntVarReference : " << &myIntVarReference << std::endl;

  std::cout << "Changing the value of myIntVar by reference" << std::endl;

  myIntVarReference = 10;

  std::cout << "myIntVar : " << myIntVar << std::endl;
  std::cout << "myIntVarReference : " << myIntVarReference << std::endl;

  return 0;
}
#include <iostream>
int main() {
  // two different var names, same value and reference
  int myIntVar{4};
  int &myIntVarReference{myIntVar};

  std::cout << "myIntVar : " << myIntVar << std::endl;
  std::cout << "myIntVarReference : " << myIntVarReference << std::endl;

  std::cout << "myIntVar : " << &myIntVar << std::endl;
  std::cout << "myIntVarReference : " << &myIntVarReference << std::endl;

  std::cout << "<=========================================>" << std::endl;
  std::cout << "Changing the value of myIntVar by reference" << std::endl;

  myIntVarReference = 10;

  std::cout << "myIntVar : " << myIntVar << std::endl;
  std::cout << "myIntVarReference : " << myIntVarReference << std::endl;

  std::cout << "<======================================>" << std::endl;
  std::cout << "Difference between pointers vs reference" << std::endl;
  // Pointers (useful to not modify the original value)
  // vs Reference (much more readable)
  double myDouble{12.32};
  double &myRefDouble{myDouble};
  double *myPointerDouble{&myDouble};

  std::cout << "myDouble : " << myDouble << std::endl;
  std::cout << "myRefDouble : " << myRefDouble << std::endl;
  std::cout << "myPointerDouble : " << myPointerDouble << std::endl;
  std::cout << "*myPointerDouble : " << *myPointerDouble << std::endl;

  std::cout << "<======================================>" << std::endl;
  std::cout << "Const reference"
            << std::endl; // cannot modify myIntVarReference
  int myIntVar_2{10};
  const int &myIntVarReference_2{myIntVar_2};
  std::cout << "myIntVar_2 : " << myIntVar_2 << std::endl;
  std::cout << "myIntVarReference_2 : " << myIntVarReference_2
            << std::endl; // do not need deference

  myIntVar_2 = 15;
  // myIntVarReference_2 = 10; // compiler error

  std::cout << "<======================================>" << std::endl;
  std::cout << "Const Pointers" << std::endl;
  // simulating reference behavior with pointers
  const int *const myIntVarPointer_2{&myIntVar_2};

  std::cout << "myIntVarPointer_2 : " << *myIntVarPointer_2
            << std::endl; // must go for deference
  // *myIntVarPointer_2 = 45; // compile error
  return 0;
}
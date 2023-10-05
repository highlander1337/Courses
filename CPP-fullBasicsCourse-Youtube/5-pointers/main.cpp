#include <iostream>

int main() {
  int number{43};
  int *p_number{&number};

  std::cout << "number : " << number << std::endl;
  std::cout << "p_number : " << p_number << std::endl;
  std::cout << "from p_number : " << *p_number << std::endl;

  int number_2{33};
  p_number = &number_2;

  std::cout << "number : " << number_2 << std::endl;
  std::cout << "p_number : " << p_number << std::endl;
  std::cout << "from p_number : " << *p_number << std::endl;

  const char *p_message{"Hello world"};

  std::cout << "The message is: " << p_message << std::endl;
  std::cout << "The message is: " << *p_message << std::endl;

  /*
    Alocating dynamic memory

    new can fail, so use try catch or std::nothrow to handle it
  */
  int *p_number1{new (std::nothrow) int};     // memory alocation junk value
  int *p_number2{new (std::nothrow) int(22)}; // use direct initialization
  int *p_number3{new (std::nothrow) int{33}}; // use uniforme initialization

  if (p_number1 != nullptr && p_number2 != nullptr && p_number3 != nullptr) {
    std::cout << "*p_number1 " << *p_number1 << std::endl;
    std::cout << "*p_number2 " << *p_number2 << std::endl;
    std::cout << "*p_number3 " << *p_number3 << std::endl;
  }

  /*
   use try catch block to handle with new fails
  */
  try {
    int *p_number4{new (std::nothrow) int};     // memory alocation junk value
    int *p_number5{new (std::nothrow) int(22)}; // use direct initialization
    int *p_number6{new (std::nothrow) int{33}}; // use uniforme initialization

    std::cout << "*p_number4 " << *p_number4 << std::endl;
    std::cout << "*p_number5 " << *p_number5 << std::endl;
    std::cout << "*p_number6 " << *p_number6 << std::endl;
    delete p_number4;
    p_number4 = nullptr;
    delete p_number5;
    p_number5 = nullptr;
    delete p_number6;
    p_number6 = nullptr;

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  /*
    Releasing and resetting dynamic memory
  */
  delete p_number1;
  p_number1 = nullptr;
  delete p_number2;
  p_number2 = nullptr;
  delete p_number3;
  p_number3 = nullptr;

  int *p_number4{new (std::nothrow) int{7}};

  // int *p_number4{};
  //  delete p_number4; its ok to delete a nullptr after allocating it
  if (p_number4) {
    std::cout << "point to a VALID address" << std::endl;
  } else {
    std::cout << "point to a INVALID address" << std::endl;
  }

  delete p_number4;
  p_number = nullptr;

  /*
   Memory leak situation
  */

  int *p_number5{new int{67}}; // Points to address1

  // should delete and reset here

  delete p_number5;
  p_number5 = nullptr;

  /*int number{55};
  p_number5 =
      &number; // now p_number5 points to address2,
               // but our program still use address1.
               // But our program lost the ability to delete and reset
  adress1,
               // because lost his location. Memory has been leaked.
  p_number5 = new int{40}; // again, memory has been leaked.

*/

  /*
    Declare an dynamic array
  */
  size_t size{10};

  int *myArray{new (std::nothrow) int[size]{1, 2, 3, 4}};

  for (size_t i{}; i < size; i++) {
    std::cout << "value :" << myArray[i] << " : " << *(myArray + i)
              << std::endl; // using i and pointer arithmetic
  }
  delete[] myArray;
  myArray = nullptr;

  return 0;
}

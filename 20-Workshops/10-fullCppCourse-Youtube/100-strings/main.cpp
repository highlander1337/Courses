#include <iostream>
#include <stdio.h>
#include <string>

int main() {
  std::string full_name; // empty string
  std::string planet{
      "Earth. Where the sky is blue"}; // Initialize with string literal
  std::string prefered_planet{planet}; // Initialize with other existing string
  std::string message{"Hello there", 5}; // Initialize with part of a string
                                         // literal Contains Hello
  std::string weird_message{4, 'e'};     // Initialize with multiple copies of a
                                         // char contains eeee
  std::string greeting{"Hello world"};
  std::string saying_hello{greeting, 6,
                           5}; // Initialize with part of an existing
                               // std::string starting at index 6, taking 5
                               // characters will contain world

  std::cout << "Full_name : " << full_name << std::endl;
  std::cout << "Planet : " << planet << std::endl;
  std::cout << "Prefered_planet : " << prefered_planet << std::endl;
  std::cout << "Message : " << message << std::endl;
  std::cout << "Weird_message : " << weird_message << std::endl;
  std::cout << "Greeting : " << greeting << std::endl;
  std::cout << "Saying_hello : " << saying_hello << std::endl;

  /*
    The good thing about std::String is that they took care of memory management
    for us automatically. Thereof is not necessary to worry about wasting
    resources when change the string value at runtime.
  */
  planet = "std::string took care of memory management and allocate a new "
           "address, returning the past one to the operational system";
  std::cout << "new String by std::string : " << std::endl;
  std::cout << planet << std::endl;

  /*
    The same is not possible with char, it will work fine, but char does not
    take care of memory management. Thereof the memory is not return to the
    operational system.
  */
  const char *planet1{"Earth. Where the sky is blue"};
  planet1 = "this is a new string in char, in another address, but the past "
            "one still exist. Therof is wasting resources.";
  std::cout << "Planet1 : " << planet1 << std::endl;
  std::cout << "new String by modifying the char pointer : " << std::endl;
  std::cout << planet1 << std::endl;
  return 0;
}
#ifndef PERSON_H
#define PERSON_H

#include <iostream>


class Person {
public:
  Person(const std::string &names_param, int age_param);

  void print_info() const { // This is a form of const-correctness in C++ and is
                            // used to indicate that the function will not
                            // change the object's internal state.
    std::cout << "name : " << full_name << ", age : " << age << std::endl;
  }

private:
  std::string full_name;
  int age;

public:
  // static variable declaration
  static int person_count;
};

#endif // PERSON_H
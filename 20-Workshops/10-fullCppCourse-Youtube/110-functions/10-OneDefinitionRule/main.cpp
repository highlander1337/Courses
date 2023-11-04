#include "person.h"
#include <iostream>

// variable : Declaration and definition
double weight{};

/*
    One definition rule for variables and class or class members:
    If there any other definition of the variable in the program, the linker
   will throw a error because he does not know what definition to choose.
*/

/*
    One definition rule for struct
    Only its possible to have another definition if the struct apears
   in other unit. See point structure defined in multiple units, e.g. main.cpp
   and point.cpp
*/

struct point {
  double m_x{};
  double m_y{};
};

/*// if we try to put another definition of the class members here, the linker
// will throw an error.

int Person::person_count = 8;

Person::Person(const std::string &names_param, int age_param)
    : full_name{names_param}, age{age_param} {
  ++person_count;
}
*/
int main() {
  // point p1;

  // std::cout << "p1_x : " << p1.m_x << ", p1_y : " << p1.m_y << std::endl;

  Person p1("Tassio Leno", 28);
  p1.print_info();
  std::cout << "Person count : " << p1.person_count << std::endl;
  Person p2("Tatiane Alves", 27);
  p2.print_info();
  std::cout << "Person count : " << p2.person_count << std::endl;

  return 0;
}
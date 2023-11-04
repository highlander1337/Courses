#include <cstring>
#include <iostream>

int main() {

  // std::strlen : Find the length of a string
  const char message1[]{"The sky is blue."};

  // array decays into pointer when we use const char*
  const char *message2{"The sky is blue."};
  std::cout << "message1 : " << message1 << std::endl;

  // strlen ignores null character
  std::cout << "strlen(message1) : " << std::strlen(message1) << std::endl;

  // includes the null character
  std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;

  // strlen still works with decayed arrays
  std::cout << "strlen(message2) : " << std::strlen(message2) << std::endl;

  // Prints size of pointer
  std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;

  std::cout << "==========================================" << std::endl;

  std::cout << std::endl;

  // std::strcmp(const char *lhs, const char *rhs)
  // Return < 0 if lhs appears before rhs in lexicographical order
  // Return = 0 if lhs and rhs compare equal
  // Return > 0 if lhs appears after rhs in lexicographical order

  std::cout << "std::strcmp : " << std::endl;

  const char *string_data1{"Alabama"};
  const char *string_data2{"Blabama"};

  char string_data3[]{"Alabama"};
  char string_data4[]{"Blabama"};

  // Print out the comparison
  std::cout << "std:: strcmp (" << string_data1 << "," << string_data2
            << ") : " << std::strcmp(string_data1, string_data2) << std::endl;

  std::cout << "std:: strcmp (" << string_data3 << "," << string_data4
            << ") : " << std::strcmp(string_data3, string_data4) << std::endl;

  // we can modify the const char* string because its a pointer to a string
  string_data1 = "Alabama";
  string_data2 = "Alabamb";

  // Print out the comparison
  std::cout << "std:: strcmp (" << string_data1 << "," << string_data2
            << ") : " << std::strcmp(string_data1, string_data2) << std::endl;

  std::cout << "==========================================" << std::endl;

  std::cout << std::endl;

  /*
    std::strncmp(const char *lhs, const char *rhs, std::size_t count)
    Return < 0 if lhs appears before rhs in lexicographical order
    Return = 0 if lhs and rhs compare equal, or if count is zero
    Return > 0 if lhs appears after rhs in lexicographical order

  */
  std::cout << "std::strncmp : " << std::endl;

  const char *string_data6{"Alabama"};
  const char *string_data7{"Blabama"};

  size_t n{3};

  // Print out the comparison
  std::cout << "std:: strncmp (" << string_data6 << "," << string_data7 << ","
            << n << ") : " << std::strncmp(string_data6, string_data7, n)
            << std::endl;

  std::cout << "==========================================" << std::endl;

  std::cout << std::endl;

  // we use std::strchr to find all the characters one by one

  const char *const str{
      "Try not. Do, or do not. There is no try."}; // make it a const string to
                                                   // prevent users from making
                                                   // it point somewhere else
  char target = 'T';
  const char *result = str;
  size_t iterations{};

  std::cout << "std::strchr : " << std::endl;
  while ((result = std::strchr(result, target)) != nullptr) {
    std::cout << "Found '" << target << "' starting at '" << result << "'\n";

    // increment result, otherwise we'll find target at the same location
    ++result;
    ++iterations;
  }

  std::cout << "Iterations : " << iterations << std::endl;

  std::cout << "==========================================" << std::endl;

  std::cout << std::endl;

  std::cout << "std::strrchr : " << std::endl;

  char input[] = "/home/user/hello.cpp";
  char *output = std::strrchr(input, '/');

  if (output)
    std::cout << output + 1
              << std::endl; // +1 because we want to start printing past the
                            // character found by std::strrchr

  std::cout << "==========================================" << std::endl;

  std::cout << std::endl;

  // Concatenation
  std::cout << "std::strcat : " << std::endl;

  char dest[50] = "Hello ";
  char src[50] = "World!";

  std::strcat(dest, src);
  std::strcat(dest, " Goodbye World!");
  std::cout << "dest : " << dest << std::endl;

  // More concatenation
  std::cout << std::endl;
  std::cout << "More std::strcat : " << std::endl;

  char *dest1 = new char[30]{'F', 'i', 'r', 'e', 'l', 'o', 'r', 'd', '\0'};
  char *source1 = new char[30]{',', 'T', 'h', 'e', ' ', 'P', 'h', 'o', 'e', 'n',
                               'i', 'x', ' ', 'K', 'i', 'n', 'g', '!', '\0'};

  std::cout << "std::strlen(dest1) : " << std::strlen(dest1) << std::endl;
  std::cout << "std::strlen(source1) : " << std::strlen(source1) << std::endl;

  std::cout << "Concatenating... " << std::endl;
  std::strcat(dest1, source1);

  std::cout << "std::strlen(dest1) : " << std::strlen(dest1) << std::endl;
  std::cout << "dest1 : " << dest1 << std::endl;

  std::cout << "==========================================" << std::endl;

  std::cout << std::endl;
  // std::strncat : concatenates n characters from src to dest and returns a
  // pointer to the result string
  // signature : char *strncat(char*dest, const char *src, std::size_t count);

  std::cout << "std::strncat : " << std::endl;
  char dest2[50]{"Hello "};

  char source2[30]{"There is a bird on my window"};

  // you can use the returned pointer immediately for print out
  // This is a pattern you'll see a lot in c++ code out there
  std::cout << std::strncat(dest2, source2, 6) << std::endl;

  // or you can do std::strncat separately and print dest2

  // std::strncat(dest2, source2, 6);
  std::cout << "The concatenated string is : " << dest2 << std::endl;
  std::cout << "==========================================" << std::endl;

  std::cout << std::endl;

  // std::strcpy - signature : char*strcpy(char* dest, const char* src);
  std::cout << std::endl;
  std::cout << "std::strcpy : " << std::endl;
  const char *source3 = "C++ is a multipurpose programming language.";
  char *dest3 = new char[std::strlen(source3) + 1]; // +1 for the null character
                                                    // '\0' Contains garbage
                                                    // data Not initialized
  std::strcpy(dest3, source3);

  std::cout << "sizeof(dest3) : " << sizeof(dest3) << std::endl;
  std::cout << "std::strlen(dest3) : " << std::strlen(dest3) << std::endl;
  std::cout << "dest3 : " << dest3 << std::endl;
  std::cout << "==========================================" << std::endl;

  std::cout << std::endl;

  // std::strncpy : Copy n characters from src to dest
  // signature : char*strncpy(char*dest, const char* src, std::size_t count)

  std::cout << std::endl;
  std::cout << "std::strncpy: " << std::endl;
  const char *source4 = "Hello";
  char dest4[] = {'a', 'b', 'c', 'd',
                  'e', 'f', '\0'}; // Have to put the terminating null char if
                                   // we want to print

  std::cout << "dest4 : " << dest4 << std::endl;

  std::cout << "Copying..." << std::endl;
  std::strncpy(dest4, source4, 5);

  std::cout << "dest4 : " << dest4 << std::endl;

  return 0;
}
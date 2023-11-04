#include <cstring>
#include <iostream>

struct books {
  char bookName[50];
  char authorName[50];
  char bookTheme[20];
};

int main() {

  const size_t repositoryLength = 5;

  books repository[repositoryLength];

  for (auto &&i : repository) {
    char bName[100];
    char bAuthor[100];
    char bTheme[100];

    std::cout << "Digite o titulo do livro: ";
    std::cin.getline(bName, sizeof(bName));
    std::cin.getline(repository->bookName, sizeof(bName));

    std::cout << "Digite o autor do livro: ";
    std::cin.getline(bAuthor, sizeof(bAuthor));

    std::cout << "Digite o tema do livro: ";
    std::cin.getline(bTheme, sizeof(bTheme));
  }

  return 0;
}
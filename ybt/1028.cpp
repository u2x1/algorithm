#include <cstdio>
#include <iostream>

int main() {
  char a;
  scanf("%c", &a);
  std::cout << "  " << a << std::endl;
  std::cout << " " << a << a << a << std::endl;
  std::cout << a << a << a << a << a << std::endl;
  std::cout << " " << a << a << a << std::endl;
  std::cout << "  " << a;
  return 0;
}

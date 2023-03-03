#include <iostream>
#include <cstring>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  char s[] = "I Love GPLT";
  const int len = strlen(s);
  orep(i, 0, len) {
    std::cout << s[i]; NL;
  }

  return 0;
}

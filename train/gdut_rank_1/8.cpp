#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int d;
  std::cin >> d;
  d+=2;
  if (d > 7) { std::cout << d-7; }
  else { std::cout << d; }

  return 0;
}

#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  double e = (1+2+3+4+4)/5.0 + (1+2+3+3)/4.0;
  std::cout << (e-3.45)/0.05;

  return 0;
}

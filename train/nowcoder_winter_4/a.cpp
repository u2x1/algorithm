#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int a, b;
  std::cin >> a >> b;
  if (a > b) { std::swap(a,b); }
  if (a == 2 && b == 3) { std::cout << 3; return 0; }
  std::cout << a;
  return 0;
}

#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int a, b; std::cin >> a >> b;
  if (a == b) { std::cout << a; }
  else { std::cout << 3-a-b; }

  return 0;
}

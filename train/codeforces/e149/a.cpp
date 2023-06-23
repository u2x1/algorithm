#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int a, b;
    std::cin >> a >> b;
    if (a % b) { std::cout << 1; NL; std::cout << a; }
    else { std::cout << 2; NL;  std::cout << a-1 << " " << 1; }
    NL;
  }

  return 0;
}

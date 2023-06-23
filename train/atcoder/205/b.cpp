#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) { int tmp; std::cin >> tmp; arr[tmp]++; }
  orep(i, 1, n+1) { if (arr[i] != 1) { std::cout << "No"; return 0; } }
  std::cout << "Yes";

  return 0;
}

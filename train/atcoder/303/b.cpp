#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  int ret  = 0;
  orep(i, 0, n) { int tmp; std::cin >> tmp; if (tmp > 10) { ret += tmp-10; } }
  std::cout << ret;

  return 0;
}

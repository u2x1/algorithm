#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int a[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> a[0] >> a[1] >> a[2];
  std::sort(a, a+3);
  if (a[0] == a[1]) { std::cout << a[2]; }
  else if (a[2] == a[1]) { std::cout << a[0]; }
  else { std::cout << 0; }

  return 0;
}

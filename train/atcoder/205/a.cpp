#include <iostream>
#include <iomanip>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cout << std::setprecision(10);
  double a, b; std::cin >> a >> b;
  std::cout << b/100*a;

  return 0;
}

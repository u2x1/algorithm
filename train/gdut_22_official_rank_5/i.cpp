#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) { std::cin >> arr[i]; }

  std::set<int> fix;
  std::set<int> gcd;
  int ret = 0;
  orep(i, 0, n/2) {
    const int l = arr[i], r = arr[n-i-1];
    if (l == r) {
      continue;
    } else {
      ret = std::__gcd(abs(l-r), ret);
    }
  }
  std::cout << (ret == 0 ? -1 : ret);

  // if (!gcd.size() && !fix.size()) { std::cout << -1; }
  // else if (fix.size() > 1) { std::cout << 1; }
  // else if (gcd.size()) {
  //   int all = 0;
  //   for(const auto x : gcd) { all = std::__gcd(all, x); }
  //   if (fix.size()) {
  //     for(const auto x : fix) {
  //       if (x <= all && std::__gcd(x, all) > 1) { std::cout << x; return 0; }
  //       else { std::cout << 1; return 0; }
  //     }
  //   } else {
  //     std::cout << all; return 0;
  //   }
  // }

  return 0;
}

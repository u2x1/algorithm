#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using i64 = long long;

const int maxN = 2e5+5;
int a[maxN], n;

bool check(const i64 x) {
  std::vector<i64> v;
  i64 cur = x;
  orep(i, 0, n) {
    if (cur < a[i]) { cur = x; v.emplace_back(a[i]); }
    else {
      while(v.size() && cur >= v.back()) {
        cur += v.back(); v.pop_back();
      }
    }
  }
  return !v.size();
}
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n;
  orep(i, 0, n) { std::cin >> a[i]; }
  i64 l = -1, r = 1ll << 62;
  while(l < r-1) {
    const i64 m = (l+r) >> 1;
    if (check(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  std::cout << r;

  return 0;
}

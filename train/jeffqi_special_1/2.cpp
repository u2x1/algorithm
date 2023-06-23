#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using i64 = long long;

struct st { i64 val, idx, len; };

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<st> rise, down;
  i64 larea = 0, rarea = 0;
  i64 ret = 0, tmp;
  orep(i, 1, n+1) {
    std::cin >> tmp;
    while(down.size() && down.back().val <= tmp) {
      larea -= down.back().val * down.back().len;
      down.pop_back();
    }
    while(rise.size() && rise.back().val >= tmp) {
      larea += rise.back().val * rise.back().len;
      rise.pop_back();
    }
    down.push_back({tmp, i, down.size() ? (i-down.back().idx) : i});
    rise.push_back({tmp, i, rise.size() ? (i-rise.back().idx) : i});
    larea += down.back().val * down.back().len;
    rarea -= rise.back().val * rise.back().len;
    ret += larea + rarea;
  }
  std::cout << ret;

  return 0;
}

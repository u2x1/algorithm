#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using i64 = long long;
struct st { int val, len; };

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<st> u; int tmp;
  orep(i, 0, n) { std::cin >> tmp; u.push_back({tmp, 1}); }

  i64 ret = 0;

  std::vector<st> stk;
  for(const auto &x : u) {
    while(stk.size() && stk.back().val < x.val) {
      const auto &bklen = stk.back().len;
      if (stk.size() > 1) { ret += bklen; }
      ret += bklen + 1ll*bklen*(bklen-1)/2;
      stk.pop_back();
    }
    if (stk.size() && stk.back().val == x.val) {
      stk.back().len++;
    } else {
      stk.push_back(x);
    }
  }
  while(stk.size()) {
    if (stk.size() > 1) { ret += stk.back().len; }
    ret += 1ll*stk.back().len*(stk.back().len-1)/2;
    stk.pop_back();
  }

  std::cout << ret;

  return 0;
}

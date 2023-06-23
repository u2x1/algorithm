#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::map<int, int> mp;
    std::map<int, int> f, g;
    int tmp; int tmp2;
    orep(i, 0, n) { std::cin >> tmp >> tmp2; mp[tmp]++; tmp2 ? g[tmp]++ : f[tmp]++; }
    std::vector<int> v, num;
    for(auto [x, y] : mp) { v.emplace_back(y); num.emplace_back(x); }
    std::sort(all(num), [&](int x, int y) { return mp[x] > mp[y]; });
    std::sort(all(v)); std::reverse(all(v));
    int mx = 0x3f3f3f3f;
    int ret1 = 0;
    std::vector<int> val;
    for(auto x : v) {
      if (mx && x >= mx) {
        --mx; ret1 += mx;
        val.emplace_back(mx);
      } else if (mx && x < mx) {
        mx = x; ret1 += mx;
        val.emplace_back(mx);
      }
    }

    int ret2 = 0;
    auto cmp = [&](int x, int y) { return g[x] < g[y]; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q(cmp);
    int i = 0;
    for(auto cur : val) {
      if (!cur) { break; }
      while(i < v.size() && mp[num[i]] >= cur) {
        q.emplace(num[i++]);
      }
      // std::cout << cur << "-" << g[q.top()]; NL;
      ret2 += std::min(cur, g[q.top()]); q.pop();
    }
    std::cout << ret1 << " " << ret2; NL;
  }

  return 0;
}

#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using lnt = long long;
const lnt inf = 1e18;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    lnt n, L; std::cin >> n >> L;
    std::vector<std::vector<std::pair<lnt, lnt>>> son(n+1);
    orep(i, 1, n) {
      int a, b, w; std::cin >> a >> b >> w;
      son[a].emplace_back(b, w);
      son[b].emplace_back(a, w);
    }
    int q; std::cin >> q;
    std::vector<int> dis(n+1);
    std::function<std::set<lnt>(int, int)> init = [&](int u, int fa) {
      
    };
  }

  return 0;
}

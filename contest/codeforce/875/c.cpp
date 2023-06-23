#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;

std::vector<std::pair<int, int>> son[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int _; std::cin >> _;
  son[0].emplace_back(1, 0);
  while(_--) {
    int n; std::cin >> n;
    orep(i, 1, n+1) { son[i].clear(); }
    orep(i, 1, n) {
      int a, b; std::cin >> a >> b;
      son[a].emplace_back(b, i);
      son[b].emplace_back(a, i);
    }
    std::vector<int> fa(n+1, 0);
    int ret = 0;
    std::queue<std::pair<int, int>> q1, q2;
    q1.emplace(0, 0);
    while(q1.size()) {
      while(q1.size()) {
        const auto [u, t] = q1.front(); q1.pop();
        // std::cout << "visiting " << u << " at " << t; NL;
        for(auto [v, tt] : son[u]) {
          if (v == fa[u]) { continue; }
          fa[v] = u;
          if (tt > t) { q1.emplace(v, tt); }
          else { q2.emplace(v, tt); }
        }
      }
      ++ret;
      std::swap(q1, q2);
    }
    std::cout << ret-1; NL;
  }

  return 0;
}

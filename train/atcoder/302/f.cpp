#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
std::vector<int> son[maxN];
int dis[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  memset(dis, 0x3f, sizeof dis);
  orep(i, 0, n) {
    int a; std::cin >> a;
    orep(j, 0, a) {
      int tmp; std::cin >> tmp;
      son[tmp+n].emplace_back(i);
      son[i].emplace_back(tmp+n);
    }
  }
  dis[n+1] = 0;
  std::vector<int> q({n+1});
  orep(i, 0ul, q.size()) {
    const auto u = q[i];
    for(auto x : son[u]) {
      if (dis[x] > dis[u]+1) {
        dis[x] = dis[u]+1;
        q.emplace_back(x);
      }
    }
  }
  if (dis[n+m] == 0x3f3f3f3f) {
    std::cout << -1;
  } else {
    std::cout << dis[n+m]/2-1;
  }

  return 0;
}

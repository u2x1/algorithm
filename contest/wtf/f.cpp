#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
double cap[maxN], water[maxN];
std::vector<int> son[maxN];
int in[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  orep(i, 1, n+1) { std::cin >> cap[i] >> water[i]; }
  orep(i, 0, k) {
    int a, b; std::cin >> a >> b;
    son[a].emplace_back(b);
    ++in[b];
  }
  int x, y, z; std::cin >> x >> y >> z;
  std::queue<int> q;
  water[x] += y;
  q.push(x);
  while(q.size()) {
    const int u = q.front(); q.pop();
    double more = (water[u] > cap[u] ? water[u] - cap[u] : 0);
    water[u] = water[u] > cap[u] ? cap[u] : water[u];
    double add = more / son[u].size();
    for(const int v : son[u]) {
      water[v] += add;
      --in[v];
      if (!in[v]) { q.push(v); }
    }
  }
  printf("%.15f", water[z]);

  return 0;
}

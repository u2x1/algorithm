#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
struct st { int x, y; } pts[maxN];

long long dis(const st a, const st b) { return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); }

struct edge { long long u, v, cost; };
bool operator<(const edge a, const edge b) { return a.cost < b.cost; }

int fa[maxN];
int find(const int x) { if (fa[x] == x) { return x; } return fa[x] = find(fa[x]); }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int p, s; std::cin >> s >> p;
  std::vector<int> permu;
  orep(i, 1, p+1) {
    std::cin >> pts[i].x >> pts[i].y;
    permu.emplace_back(i);
    fa[i] = i;
  }
  std::vector<edge> es;
  orep(i, 0, permu.size()) {
    orep(j, i+1, permu.size()) {
      es.push_back({permu[i], permu[j], dis(pts[permu[i]], pts[permu[j]])});
    }
  }
  std::sort(es.begin(), es.end());

  std::vector<long long> added;
  for(const auto e : es) {
    if (find(e.u) == find(e.v)) { continue; }
    fa[find(e.u)] = find(e.v);
    added.emplace_back(e.cost);
  }
  std::sort(added.rbegin(), added.rend());
  int cnt = 1;
  for(const int x : added) { 
    if (cnt == s) { printf("%.2f", sqrt(x)); }
    ++cnt;
  }

  return 0;
}

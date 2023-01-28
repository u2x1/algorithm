#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
bool used[maxN];

struct edge { int from, to, w; } edges[maxN]; int cnt;
bool operator<(const edge a, const edge b) { return a.w < b.w; }

int par[maxN];
int find(const int x) { return x == par[x] ? x : (par[x] = find(par[x])); }
void merge(const int x, const int y) { const int u = find(x), v = find(y); if (u != v) { par[u] = v; } }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  while(1) {
    int pts; std::cin >> pts;
    if (!pts) { break; }
    int routes; std::cin >> routes;
    orep(i, 0, routes) {
      std::cin >> edges[cnt].from >> edges[cnt].to >> edges[cnt].w;
      cnt++;
    }
    std::sort(edges, edges+cnt);
    long long rst=0;
    orep(i, 1, pts+1) { par[i] = i; }
    orep(i, 0, cnt) {
      if (find(edges[i].from) == find(edges[i].to)) { continue; }
      merge(edges[i].from, edges[i].to);
      rst += edges[i].w;
    }
    std::cout << rst; NL;
    orep(i, 1, pts+1) { used[i] = 0; }
    cnt = 0;
  }
  return 0;
}

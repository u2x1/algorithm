#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e4+5;
long long dis[maxN];
struct edge { int to,w; };
std::vector<edge> e[maxN];
bool vis[maxN];

struct node { int v; };
bool operator>(const node a, const node b) { return dis[a.v] > dis[b.v]; }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, s, t; std::cin >> n >> m >> s >> t;
  orep(i, 0, m) {
    int from, to, w; std::cin >> from >> to >> w;
    e[from].push_back({to, w});
    e[to].push_back({from, w});
  }

  memset(dis, 63, (n+2)*sizeof(long long));
  dis[s] = 0ll;
  std::priority_queue<node, std::vector<node>, std::greater<node>> q;
  q.push({s});
  while(!q.empty()) {
    const int vv = q.top().v;
    q.pop();
    if (vis[vv]) { continue; }
    vis[vv] = 1;
    orep(it, e[vv].cbegin(), e[vv].cend()) {
      const int tt = it->to, ww = it->w;
      if (dis[tt] > dis[vv] + ww) {
        dis[tt] = dis[vv] + ww;
        q.push({tt});
      }
    }
  }
  std::cout << dis[t];

  return 0;
}

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e3+5;
long long dis[maxN];
struct edge { int to, w; };
std::vector<edge> e[maxN];
struct node { int v; };
bool operator<(const node a, const node b) { return dis[a.v] > dis[b.v]; }
bool vis[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t, n; std::cin >> t >> n;
  orep(i, 0, t) {
    int from, to, w; std::cin >> from >> to >> w;
    edge a; a.to = to; a.w = w;
    e[from].push_back(a);
    edge b; b.to = from; b.w = w;
    e[to].push_back(b);
  }
  memset(dis, 63, sizeof(dis));
  dis[n] = 0;
  std::priority_queue<node> q;
  node ndv; ndv.v = n;
  q.push(ndv);
  while(!q.empty()) {
    const int vv = q.top().v;
    q.pop();
    if (vis[vv]) { continue; }
    vis[vv] = 1;
    orep(it, 0, e[vv].size())  {
      const int to = e[vv][it].to, w = e[vv][it].w;
      if (dis[to] > dis[vv] + w) {
        dis[to] = dis[vv] + w;
        node nd; nd.v = to;
        q.push(nd);
      }
    }
  }
  std::cout << dis[1];

  return 0;
}

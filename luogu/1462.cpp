#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
struct edge { int to, cost; };
std::vector<edge> son[maxN];

int fee[maxN];

long long dis[maxN];
bool vis[maxN];

struct st { int u; };
bool operator<(const st a, const st b) { return dis[a.u] > dis[b.u]; }

int n, m, b;
bool check(const long long limit) {
  memset(dis, 0x3f, sizeof dis);
  memset(vis, 0, sizeof vis);
  std::priority_queue<st> q;
  q.push({1}); dis[1] = 0;
  if (fee[1] > limit) { return 0; }
  while(q.size()) {
    const int v = q.top().u; q.pop();
    if (vis[v]) { continue; } vis[v] = 1;
    for(auto e : son[v]) {
      if (fee[e.to] > limit) { continue; }
      if (vis[e.to]) { continue; }
      if (dis[e.to] > dis[v] + e.cost) {
        dis[e.to] = dis[v] + e.cost;
        q.push({e.to});
      }
    }
  }
  return (dis[n] <= b);
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> m >> b;
  orep(i, 1, n+1) { std::cin >> fee[i]; }
  orep(i, 0, m) {
    int l, r, c; std::cin >> l >> r >> c;
    son[l].push_back({r, c});
    son[r].push_back({l, c});
  }
  int l = -1, r = 1e9+1;
  while(l < r-1) {
    const long long mid = (l+r) >> 1;
    if (!check(mid)) { l = mid; }
    else { r = mid; }
  }
  if (r == 1e9+1) { std::cout << "AFK"; }
  else { std::cout << r; }

  return 0;
}

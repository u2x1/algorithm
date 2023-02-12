#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e3+5;

std::string arr[maxN];
int dis[maxN]; bool vis[maxN];

struct st { int v; };
bool operator<(const st a, const st b) { return dis[a.v] > dis[b.v]; }

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, n) {
    std::cin >> arr[i];
  }
  std::vector<std::vector<int>> e(n+m+1);
  orep(i, 0, n) {
    orep(j, 0, m) {
      if (arr[i][j] == '#') {
        e[i].push_back(j+n);
        e[j+n].push_back(i);
      }
    }
  }
  memset(dis, 0x3f, sizeof(dis));
  dis[0] = 0;
  std::priority_queue<st> q;
  q.push({0});
  while(!q.empty()) {
    const int v = q.top().v; q.pop();
    if (vis[v]) { continue; }
    vis[v] = 1;
    orep(it, e[v].cbegin(), e[v].cend()) {
      int u = *it;
      if (dis[u] > dis[v] + 1) {
        dis[u] = dis[v]+1;
        q.push({u});
      }
    }
  }
  std::cout << (dis[n-1] == 0x3f3f3f3f ? -1 : dis[n-1]);
  return 0;
}

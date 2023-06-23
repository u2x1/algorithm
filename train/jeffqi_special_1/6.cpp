#include <iostream>
#include <cstring>
#include <queue>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
bool vis[maxN][maxN];
int dis[maxN][maxN];
bool a[maxN][maxN];

struct st { int x, y, c; };

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  int r, c; std::cin >> r >> c;
  int x, y; std::cin >> x >> y;
  std::string s;
  orep(i, 1, n+1) {
    std::cin >> s;
    orep(j, 1, m+1) {
      a[i][j] = s[j-1] == '*';
    }
  }
  memset(dis, 0x3f, sizeof(dis));
  std::queue<st> q;
  q.push({r, c, 0});
  int ret = 0;
  while(q.size()) {
    const st &t = q.front();
    if (t.c > x) { continue; }
    if (t.c + t.y-c > y) { continue; }
    if (dis[t.x][t.y] > c) {
      dis[t.x][t.y] = c;
      if (!vis[t.x][t.y]) { vis[t.x][t.y] = 1; ++ret; }
      q.push(
    }
  }
  std::cout << ret;

  return 0;
}

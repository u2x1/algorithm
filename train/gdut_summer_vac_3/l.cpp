#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 5e2+5;
struct st { int t, sx, sy, tx, ty; } taxi[maxN];
int vis[maxN];
std::vector<int> e[maxN];
int n, match[maxN];

inline bool dfs(int x, int color) {
  if (color == vis[x]) { return 0; }
  vis[x] = color;
  orep(it, 0, e[x].size()) {
    const int i = e[x][it];
    if (!~match[i] || dfs(match[i], color)) { match[i] = x; return 1; }
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int tc; std::cin >> tc;
  while(tc--) {
    orep(i, 0, n) { e[i].clear(); }
    memset(match, -1, sizeof(match));
    memset(vis, -1, sizeof(vis));
    std::cin >> n;
    orep(i, 0, n) {
      char c;
      int hh, mm, sx, sy, tx, ty;
      std::cin >> hh >> c >> mm >> sx >> sy >> tx >> ty;
      const int t = hh * 60 + mm;
      taxi[i].t = t;
      taxi[i].sx = sx; taxi[i].sy = sy;
      taxi[i].tx = tx; taxi[i].ty = ty;
    }
    orep(i, 0, n) {
      orep(j, 0, n) {
        if (i == j) { continue; }
        int ti = abs(taxi[i].ty - taxi[i].sy) + abs(taxi[i].tx - taxi[i].sx);
        int tj = abs(taxi[i].ty - taxi[j].sy) + abs(taxi[i].tx - taxi[j].sx);
        if (taxi[i].t + ti + tj < taxi[j].t) { e[i].push_back(j); }
      }
    }
    int ret = n;
    orep(i, 0, n) {
      ret -= dfs(i, i);
    }
    std::cout << ret; NL;
  }

  return 0;
}

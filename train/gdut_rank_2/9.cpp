#include <iostream>
#include <cstring>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

std::vector<std::vector<int>> son;
const int maxN = 5e2+5;
int arr[maxN];
bool lost[maxN];
bool conn[maxN][maxN];

bool vis[maxN];
bool checkConn(const int u, const int v) {
  if (u==v || conn[u][v]) { return 1; }
  orep(i, 0ul, son[u].size()) {
    const int vv = son[u][i];
    if (vis[vv] || lost[vv] || !conn[u][vv]) { continue; } vis[vv] = 1;
    if (checkConn(vv, v)) { return 1; }
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  son = std::vector<std::vector<int>>(n+1);
  orep(i, 0, m) {
    int a, b;
    std::cin >> a >> b;
    if (conn[a][b]) { continue; }
    conn[a][b] = conn[b][a] = 1;
    son[a].push_back(b);
    son[b].push_back(a);
  }

  int k; std::cin >> k;
  orep(i, 0, k) {
    int u; std::cin >> u;
    lost[u] = 1;
    std::vector<int> newson;
    orep(j, 0ul, son[u].size()) {
      const int v = son[u][j];
      conn[u][v] = conn[v][u] = 0;
      if (lost[v]) { continue; }
      newson.push_back(v);
    }
    bool red = 0;
    orep(g, 0ul, newson.size()) {
      orep(j, 0ul, g) {
        const int uu = newson[j];
        const int vv = newson[g];
        memset(vis, 0, sizeof(vis));
        vis[uu] = 1;
        if (!checkConn(uu, vv)) {
          red = 1;
          goto fend;
        }
      }
    }
fend:
    if (red) {
      std::cout << "Red Alert: City " << u << " is lost!"; NL;
    } else {
      std::cout << "City " << u << " is lost."; NL;
    }
  }
  if (n == k) { std::cout << "Game Over."; }

  return 0;
}

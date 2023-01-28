#include <iostream>
#include <vector>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e3+5;
int n, m, eCnt;
int vis[maxN], match[maxN];
bool pass[maxN][maxN];

bool dfs(int x) {
  orep(i, 1, m+1) {
    if (vis[i] || !pass[x][i]) { continue; }
    vis[i] = 1;
    if (!match[i] || dfs(match[i])) { match[i] = x; return 1; }
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> m >> eCnt;
  orep(i, 0, eCnt) {
    int l, r; std::cin >> l >> r;
    pass[l][r] = 1;
  }
  int ret = 0;
  orep(i, 1, n+1) {
    memset(vis, 0, sizeof(int)*(m+1));
    if (dfs(i)) { ret++; }
  }
  std::cout << ret;

  return 0;
}

#include <iostream>
#include <cstring>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 5e5+5;
int arr[maxN], id[maxN], cnt, faa[maxN];

std::vector<int> son[maxN];

int s;
void dfs(const int u = s, const int fa = 0) {
  arr[cnt++] = u;
  id[u] = cnt-1;
  faa[u] = fa;
  for (const auto x : son[u]) {
    if (fa == x) { continue; }
    dfs(x, u);
  }
}

int lg[maxN], A[maxN];
int dp[maxN][20];
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 2, maxN) { lg[i] = lg[i>>1] + 1; }
  int n, m; std::cin >> n >> m >> s;
  orep(i, 1, n) {
    int x, y; std::cin >> x >> y;
    son[x].emplace_back(y);
    son[y].emplace_back(x);
  }
  dfs();
  orep(i, 0, cnt-1) { dp[i][0] = id[faa[arr[i+1]]]; }
  orep(k, 1, 20) {
    for(int i = 0; i+(1<<k) < cnt; ++i) {
      dp[i][k] = std::min(dp[i][k-1], dp[i+(1<<(k-1))][k-1]);
    }
  }
  orep(i, 0, m) {
    int a, b; std::cin >> a >> b;
    if (a == b) { std::cout << a; NL; continue; }
    if (id[a] > id[b]) { std::swap(a, b); }
    const int ida = id[a], idb = id[b]-1;
    const int k = lg[idb-ida+1];
    std::cout << arr[std::min(dp[ida][k], dp[idb-(1<<k)+1][k])]; NL;
  }

  return 0;
}

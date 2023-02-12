#include <iostream>
#include <vector>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 3e3+5;
int arr[maxN], dp[maxN][maxN];
int n, m;
struct st { int to, w; };
std::vector<std::vector<st>> e;

int init(int u = 1) {
  if (u > n-m) { dp[u][1] = arr[u]; return 1; }
  dp[u][0] = 0;
  int user = 0;
  orep(i, 0ul, e[u].size()) {
    int v = e[u][i].to, w = e[u][i].w;
    int cur = init(v);
    user += cur;
    for(int j = user; j > 0; --j) {
      orep(k, 1, 1+std::min(j, cur)) {
        dp[u][j] = std::max(dp[u][j], dp[u][j-k] + dp[v][k] - w);
      }
    }
  }
  return user;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> m;
  e = std::vector<std::vector<st>>(n+1);
  orep(i, 0, n-m) {
    int k; std::cin >> k;
    orep(j, 0, k) {
      int t, w; std::cin >> t >> w;
      e[i+1].push_back({t, w});
    }
  }
  memset(dp, -0x3f, sizeof(dp));
  orep(i, n-m+1, n+1) { std::cin >> arr[i]; }
  init();
  for(int i = m; i > 0; i--) {
    if (dp[1][i] >= 0) { std::cout << i; return 0; }
  }
}

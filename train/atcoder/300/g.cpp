#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
long long N, P;
int p[100], cnt; bool vis[100];

long long ret = 0;
int memo[maxN][100];

void dfs(long long n, int i) {
  if (i == -1) { ret += 1; return; }
  // if (i == 0) { ret += std::__lg(n)+1; return; }
  if (n < maxN && memo[n][i]) { ret += memo[n][i]; return; }
  int ans = ret;
  dfs(n, i-1);
  if (n >= p[i]) { dfs(n/p[i], i); }
  if (n < maxN) { memo[n][i] = ret - ans; }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N >> P;
  orep(i, 2, P+1) {
    if (!vis[i]) { p[cnt++] = i; }
    for(int j = 0; j < cnt && p[j] * i <= P; ++j) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0) { break; }
    }
  }
  dfs(N, cnt-1);
  std::cout << ret;

  return 0;
}

#include <iostream>
#include <vector>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 5e5+5;
std::string s; int n;
int fa[maxN];
std::vector<int> son[maxN];
long long dp[maxN];
long long cont[maxN];
long long stk[maxN]; int stkcnt = 0;

void dfs(const int u = 1, const int faa = 0) {
  dp[u] = dp[faa];
  if (s[u] == '(') {
    stk[stkcnt++] = u;
    for(auto v : son[u]) { dfs(v, u); }
    stk[--stkcnt] = 0;
  } else if (s[u] == ')' && stkcnt != 0) {
    int taken = stk[--stkcnt];
    stk[stkcnt] = 0;
    cont[u] = cont[fa[taken]] + 1;
    dp[u] += cont[u];
    for(auto v : son[u]) { dfs(v, u); }
    stk[stkcnt++] = taken;
  } else {
    for(auto v : son[u]) { dfs(v, u); }
  }
//  std::cout << u  << ": " <<dp[u]; NL;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> s;
  s = " " + s;
  orep(i, 2, n+1) { std::cin >> fa[i]; son[fa[i]].push_back(i); }
  dfs();
  long long ret = 0;
  orep(i, 1, n+1) { ret ^= (dp[i] * i); }
  std::cout << ret;

  return 0;
}

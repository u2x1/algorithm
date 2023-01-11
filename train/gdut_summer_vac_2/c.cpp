#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          putchar(10);
#define magic 80112002;

const int maxN = 5e3+10;
int dp[maxN];
std::vector<int> out[maxN], in[maxN];
int stk[maxN]; int c;

int down(int x) {
  if (!in[x].size()) { return 1; }
  if (dp[x]) { return dp[x]; }
  int me = 0;
  orep(i, 0u, in[x].size()) {
    me = (me + down(in[x][i])) % magic;
  }
  return dp[x] = me;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  orep(i, 0, m) {
    int a, b; scanf("%d%d", &a, &b);
    out[a].push_back(b);
    in[b].push_back(a);
  }

  int ret = 0;
  orep(i, 1, n+1) {
    if (!out[i].size()) { ret = (ret + down(i)) % magic; }
  }
  printf("%d", ret);

  return 0;
}

#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 3e6+5;
std::pair<int, int> rg[maxN];
int dp[maxN];

int main() {
  int n; scanf("%d", &n);
  int mx = 0;
  orep(i, 0, n) {
    int l,r; scanf("%d%d", &l, &r);
    rg[i].first = l-1; rg[i].second = r;
    mx = std::max(r, mx);
  }
  std::sort(rg, rg+n, [](auto a, auto b){return a.second<b.second;});
  int idx = 0;
  orep(r, 0, mx+1) {
    dp[r] = dp[r-1];
    while(r == rg[idx].second) {
      const int l = rg[idx].first;
      dp[r] = std::max(dp[r], dp[l]+r-l);
      ++idx;
    }
  }
  printf("%d", dp[mx]);
  return 0;
}

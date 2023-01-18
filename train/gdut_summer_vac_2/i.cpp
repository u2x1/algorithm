#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 8e5+5;

struct st { int l; int r; };
long long dp[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

  int n; std::cin >> n;
  std::vector<st> vl(n), vr(n);
  long long ret = 0;

  orep(i, 0, n) {
    int a, b; std::cin >> a >> b;
    if (a < 0 && b < 0) { continue; }
    if (a >= 0 && b >= 0) { ret += a + b; continue; }
    if (a > 0)  { vl.push_back({a, b}); }
    if (b > 0)  { vr.push_back({a, b}); }
  }

  memset(dp, -0x7f, sizeof(dp));
  dp[400000] = 0;
  orep(i, 0ul, vr.size()) {
    orep(j, 0, maxN-1+vr[i].l){
      dp[j] = std::max(dp[j-vr[i].l] + vr[i].r, dp[j]);
    }
  }
  orep(i, 0ul, vl.size()) {
    for(int j = maxN-1; j >= vl[i].l; --j) {
      dp[j] = std::max(dp[j-vl[i].l] + vl[i].r, dp[j]);
    }
  }
  long long max = 0;
  orep(i, 400000, maxN) {
    if (dp[i] >= 0) {
      max = std::max(dp[i] + i - 400000, max);
    }
  }
  std::cout << max + ret;

  return 0;
}

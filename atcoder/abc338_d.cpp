#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, m; std::cin >> m >> n;
  int last = 1;
  lnt raw = 0;
  std::vector<lnt> sum(m+2);
  for (int i = 0; i < n; ++i) {
    int x; std::cin >> x;
    if (i == 0) { last = x; continue; }
    raw += std::min(std::abs(x - last), m - std::abs(x - last));
    if (2 * std::abs(x - last) != m) {
      int l = std::min(x, last), r = std::max(x, last);
      if (2 * (r - l) < m) {
        sum[l] += m - 2 * (r - l);
        sum[r] -= m - 2 * (r - l);
      } else {
        sum[1] += 2 * (r - l) - m;
        sum[l] -= 2 * (r - l) - m;
        sum[r] += 2 * (r - l) - m;
      }
    }
    last = x;
  }
  lnt ret = linf;
  for (int i = 1; i <= m; ++i) {
    sum[i+1] += sum[i];
    ret = std::min(ret, raw + sum[i]);
  }
  std::cout << ret;

  return 0;
}

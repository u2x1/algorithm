#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, q; std::cin >> n >> q;
  std::vector sum(n+2, std::vector<int>(n+2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char c; std::cin >> c;
      sum[i][j] += c == 'B';
      sum[i][j+1] += sum[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sum[i+1][j] += sum[i][j];
    }
  }
  auto g = [&](int x, int y) {
    lnt l = x / n, r = y / n;
    return sum[n][n] * (l * r)
      + sum[n][y - r*n] * l
      + sum[x - l*n][n] * r
      + sum[x - l*n][y - r*n];
  };
  while (q--) {
    int a, b, c, d; std::cin >> a >> b >> c >> d;
    ++a, ++b, ++c, ++d;
    std::cout << g(c, d) - g(c, b-1) - g(a-1, d) + g(a-1, b-1); NL;
  }

  return 0;
}

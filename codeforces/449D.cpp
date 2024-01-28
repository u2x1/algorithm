#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;
const int mo = 1e9+7;

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;

  const int u = (1 << 20) - 1;
  std::vector<lnt> f(u+1);

  for (int i = 0; i < n; ++i) {
    int x; std::cin >> x;
    f[x] ++;
  }

  for (int d = 0; d < 20; ++d) {
    for (int s = 0; s <= u; ++s) {
      if (!(s >> d & 1)) {
        f[s] += f[s | (1 << d)];
      }
    }
  }

  std::vector<lnt> pw({1});
  pw.reserve(n+1);
  for (int i = 0; i < n; ++i) { pw.emplace_back(pw.back() * 2 % mo); }

  lnt ret = 0;
  for (int s = 0; s <= u; ++s) {
    int c = __builtin_popcount(s);
    f[s] = pw[f[s]] - 1;
    (ret += ((c & 1) ? -1 : 1) * f[s]) %= mo; 
  }

  std::cout << (ret + mo) % mo;

  return 0;
}

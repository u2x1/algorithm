#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;

  const int u = (1 << 24) - 1;
  std::vector<lnt> f(u+1);

  for (int i = 0; i < n; ++i) {
    std::string x; std::cin >> x;
    int s = 0;
    for (auto c : x) {
      s |= (1 << (c - 'a'));
    }
    f[s]++;
  }

  for (int d = 23; d != -1; --d) {
    for (int s = 0; s <= u; ++s) {
      if (s >> d & 1) {
        f[s] += f[s ^ (1 << d)];
      }
    }
  }

  lnt ret = 0;
  for (int s = 0; s <= u; ++s) {
    ret ^= (n - f[s]) * (n - f[s]);
  }
  std::cout << ret;

  return 0;
}

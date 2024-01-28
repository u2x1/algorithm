#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {

    std::vector<std::pair<int, int>> v(3);

    for (int i = 0; i < 3; ++i) {
      std::cin >> v[i].first >> v[i].second;
    }

    lnt ret = linf;
    std::sort(all(v));
    do {
      lnt w = 0, h = 0;
      static auto merge = [&](lnt a, lnt b, int o, int oo) {
        if (oo) { std::swap(a, b); }
        if (o == 0) {
          w = std::max(a, w);
          h += b;
        } else {
          h = std::max(a, h);
          w += b;
        }
      };
      for (int ss = 0; ss < 8; ++ss) {
        for (int s = 0; s < 8; ++s) {
          w = 0, h = 0;
          for (int i = 0; i < 3; ++i) {
            merge(v[i].first, v[i].second, s >> i & 1, ss >> i & 1);
          }
          ret = std::min(ret, 1ll * w * h);
        }
      }
    } while (std::next_permutation(all(v)));
    std::cout << ret; NL;
  }

  return 0;
}

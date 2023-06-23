#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::map<int, int> mp;
  std::vector<long long> v(n);
  const int inf = 0x3f3f3f3f;
  std::vector<int> rmzr(33, inf);
  auto upd = [&](long long x, int idx) {
    for(int i = 0; i < 33; ++i) {
      if (((x>>i)&1) == 0) { rmzr[i] = idx; }
    }
  };
  long long ret = 0;
  orep(i, 0, n) {
    std::cin >> v[i];
    upd(v[i], i);
    int lms = inf;
    for(auto x : rmzr) {
      if (x == inf) { goto fend; }
      lms = std::min(x, lms);
    }
    ret += lms+1;
fend:;
  }
  std::cout << ret;

  return 0;
}

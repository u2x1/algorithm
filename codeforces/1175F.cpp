#include <bits/stdc++.h>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using ui64 = unsigned long long;

struct hs { ui64 h1, h2; };
bool operator==(const hs &a, const hs &b) { return a.h1 == b.h1 && a.h2 == b.h2; }
hs operator^(const hs a, const hs b) { return { a.h1 ^ b.h1, a.h2 ^ b.h2 }; }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  ui64 ret = 0;

  std::vector<int> v(n);
  for(auto &x : v) { std::cin >> x; ret += x==1; }

  std::vector<hs> hash(n+1), per(n+1), sum(n+1);
  std::mt19937_64 rnd(std::random_device{}());
  orep(i, 1, n+1) { hash[i] = {rnd(), rnd()}; }
  orep(i, 1, n+1) { per[i] = per[i-1] ^ hash[i]; }

  auto f = [&]() {
    for(int i = 0, mx; i < n; ++i) {
      sum[i+1] = sum[i] ^ hash[v[i]];
      if (v[i] == 1) { mx = 1; continue; }
      mx = std::max(mx, v[i]);
      if (i+1 >= mx && (sum[i+1] ^ sum[i+1-mx]) == per[mx]) { ++ret; }
    }
  };

  f();
  std::reverse(v.begin(), v.end());
  f();

  std::cout << ret;

  return 0;
}

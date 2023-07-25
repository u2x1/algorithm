#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> a(n+1), b(n+1), c(n+1);
  orep(i, 1, n+1) { std::cin >> a[i]; }
  orep(i, 1, n+1) { std::cin >> b[i]; }
  orep(i, 1, n+1) { std::cin >> c[i]; }
  const int inf = 0x3f3f3f3f;
  std::map<unsigned long long, int> mp;
  int x = 1, y = 1, z = 1;
  using ull = unsigned long long;
  auto hash = [](ull x, ull y, ull z) { return x * 1000000000000000000ull + y * 1000000000000ull + z; };
  orep(i, 0, n*10) {
    ull h = hash(x, y, z);
    // std::cout << h; NL;
    if (!mp.count(h)) { mp[h] = inf; }
    mp[h] = std::min(mp[h], i);
    int tx = a[y], ty = b[z], tz = c[x];
    x = tx, y = ty, z = tz;
  }
    ull h = hash(x, y, z);
    if (!mp.count(h)) { mp[h] = inf; }
    mp[h] = std::min(mp[h], n);
  int q; std::cin >> q;
  while(q--) {
    int a, b, c; std::cin >> a >> b >> c;
    std::cout << (!mp.count(hash(a, b, c)) ? -1 : mp[hash(a, b, c)]); NL;
  }

  return 0;
}

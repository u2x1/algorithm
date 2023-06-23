#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::vector<int> v(n);
    for(auto &x : v) { std::cin >> x; }
    int ret = 0;
    orep(i, 0, n) {
      if (s[i] == '0') { continue; }
      int cur = 0; int m = 0;
      if (i) { cur += v[i-1]; m = v[i-1]; }
      for(;i < n && s[i] == '1'; ++i) {
        m = std::min(m, v[i]);
        cur += v[i];
      }
      if (m) { cur -= m; }
      ret += cur;
    }
    std::cout << ret; NL;
  }

  return 0;
}

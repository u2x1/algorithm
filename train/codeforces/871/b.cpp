#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n); for(auto &x: v) { std::cin >> x; }
    int ret = 0;
    for(int i = 0; i < n; ++i) {
      int x = v[i];
      if (x == 1) { continue; }
      int cnt = 0;
      for(int  j = i; j < n && v[j] == 0; ++j) {
        cnt++;
      }
      ret = std::max(ret, cnt);
    }
    std::cout << ret; NL;
  }

  return 0;
}

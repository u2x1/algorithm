#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::map<long long, int> v1, v2, v3, v4;
    orep(i, 0, n) {
      int a, b; std::cin >> a >> b;
      v1[a+b]++; v2[b-a]++; v3[a]++; v4[b]++;
    }
    long long ret = 0;
    for(auto [_, x] : v1) { ret += x*(x-1); }
    for(auto [_, x] : v2) { ret += x*(x-1); }
    for(auto [_, x] : v3) { ret += x*(x-1); }
    for(auto [_, x] : v4) { ret += x*(x-1); }
    std::cout << ret; NL;
  }

  return 0;
}

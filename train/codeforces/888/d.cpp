#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<long long> v;
    std::map<long long, int> mp;
    orep(i, 1, n) {
      long long x; std::cin >> x;
      mp[v.size() ? x - v.back() : x]++;
      v.emplace_back(x);
    }
    std::vector<long long> miss;
    for(int i = 1; i <= n; ++i) {
      if (mp.count(i) == 0) { miss.emplace_back(i); }
      else if (mp[i] == 1) { mp.erase(i); }
    }
    if (miss.size() == 1) { std::cout << "YES"; NL; continue; }
    else if (miss.size() == 2) {
      auto [x, y] = *mp.begin();
      std::cout << (miss[0] + miss[1] == x ? "YES" : "NO"); NL;
    } else {
      std::cout << "NO"; NL;
    }
  }

  return 0;
}

#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n), v2(n);
    orep(i, 0, n) {
      std::cin >> v[i] >> v2[i];
    }
    std::vector<int> idx(n); std::iota(all(idx), 0);
    std::sort(idx.rbegin(), idx.rend() , [&](const int a, const int b) { return v[a]+v2[a] < v[b]+v2[b]; });
    long long a = 0, b = 0;
    orep(i, 0, n) {
      i % 2 == 0 ? a += v[idx[i]] : b += v2[idx[i]];
    }
    std::cout << a - b; NL;
  }

  return 0;
}

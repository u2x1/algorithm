#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

struct BIT {
  std::vector<int> v; int n;
  BIT(int a) : v(a), n(a) {}
  void add(int p, int x) {
    while(p <= n) {
      v[p] += x;
      p += p & -p;
    }
  }
  int get(int p) {
    int ret = 0;
    while(p) {
      ret += v[p];
      p -= p & -p;
    }
    return ret;
  }
};

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n);
    for(auto &x : v) { std::cin >> x; }
    std::reverse(all(v));
    BIT tree(1e6+5);
    int ret = 0;
    for(auto x : v) {
      tree.add(x, 1);
      ret += (tree.get(x-1) > 0);
      // std::cout << ret  << " ";
    }
    std::cout << ret; NL;
  }

  return 0;
}

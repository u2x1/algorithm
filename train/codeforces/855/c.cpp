#include <iostream>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int a[maxN];
int q;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    orep(i, 0, n) { std::cin >> a[i]; }
    std::multiset<int> s;
    auto limit = 0ul;
    for(int i = n-1; ~i; --i) {
      if (a[i] == 0) { limit++; }
      else {
        s.insert(a[i]);
        if (s.size() > limit) { s.erase(s.begin()); }
      }
    }
    long long ret = 0;
    for(auto x : s) { ret += x; }
    std::cout << ret; NL;
  }

  return 0;
}

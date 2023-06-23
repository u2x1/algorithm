#include <iostream>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int a[maxN], b[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::map<int, int> mp1, mp2;
    int n; std::cin >> n;
    orep(i, 0, n) { std::cin >> a[i]; }
    orep(i, 0, n) { std::cin >> b[i]; }
    orep(i, 0, n) {
      int j = i; while(j < n && a[j] == a[i]) { ++j; }
      mp1[a[i]] = std::max(mp1[a[i]], j-i); i = j-1;
    }
    orep(i, 0, n) {
      int j = i; while(j < n && b[j] == b[i]) { ++j; }
      mp2[b[i]] = std::max(mp2[b[i]], j-i); i = j-1;
    }
    int ret = 0;
    for(auto [x, y] : mp1) {
      ret = std::max(ret, mp1[x]+mp2[x]);
    }
    for(auto [x, y] : mp2) {
      ret = std::max(ret, mp1[x]+mp2[x]);
    }
    std::cout << ret; NL;
  }

  return 0;
}

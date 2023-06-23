#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    char tmx = 'a', smx = 'a';
    int lens = 1, lent = 1;
    std::map<char, int> mpa, mpb;
    while(n--) {
      int e, k; std::string s; std::cin >> e >> k >> s;
      k *= s.size();
      if (e == 1) {
        lens += k;
        for(auto c : s) { smx = std::max(c, smx); }
      } else {
        lent += k;
        for(auto c : s) { tmx = std::max(c, tmx); }
      }
      if (tmx != 'a' || (lens < lent && smx == 'a')) { std::cout << "YES"; }
      else { std::cout << "NO"; }
      NL;
    }
  }

  return 0;
}

#include <iostream>
#include <bitset>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  std::set<long long> sq;
  orep(i, 1ll, 100000ll) { sq.insert(i*i); }
  int n = s.size();
  int ret = -1;
  orep(st, 1, (1<<n)) {
    int x = 0; bool fine = 1;
    orep(i, 0, n) {
      if ((st >> (n-1-i)) & 1) {
        if (!x && s[i] == '0') { fine = 0; }
        x = x*10 + s[i]-'0';
      }
    }
    if (fine && sq.count(x)) {
      ret = std::max(ret, __builtin_popcount(st));
    }
  }
  std::cout << (~ret ? n-ret : ret);
 
  return 0;
}

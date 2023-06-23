#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int k; std::cin >> k;
    std::string s; std::cin >> s;
    int cnt = 0;
    for(auto c : s) { cnt += (c=='1'); }
    int x = 0;
    std::vector<int> retv;
    for(int i = s.size() - 1, j = 0; j < cnt; --i, ++j) {
      if (s[i] == '0') { ++x; retv.emplace_back(i+1); }
    }
    for(int i = 0; i < s.size() && x; ++i) { 
      if (s[i] == '1') { retv.emplace_back(i+1); --x; }
    }
    std::sort(all(retv));
    std::cout << (retv.size() > 0); NL;
    if (retv.size()) {
      std::cout << retv.size();
      for(auto x : retv) { std::cout << " " << x; } NL;
    }
  }
    
  return 0;
}

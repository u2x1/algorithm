#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::string s1, s2; std::cin >> s1 >> s2;
    std::reverse(all(s1)); std::reverse(all(s2));
    int mx = std::max(s1.size(), s2.size());
    if (s1.size() < mx) { s1 += std::string(mx-s1.size(), '0'); }
    if (s2.size() < mx) { s2 += std::string(mx-s2.size(), '0'); }
    std::reverse(all(s1)); std::reverse(all(s2));
    // std::cout << s1 << " " << s2; NL;
    for(int i = 0; i < s1.size(); ++i) {
      if (s1[i] == s2[i]) { continue; }
      std::cout << std::abs(s1[i]-s2[i])+9*(s1.size()-i-1);
      goto fend;
    }
    std::cout << 0;
fend:; NL;
  }

  return 0;
}

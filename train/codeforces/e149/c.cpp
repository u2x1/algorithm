#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 5e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::string s; std::cin >> s;
    s[0] = s[0] == '?' ? '0' : s[0];
    for(int i = s.size()-1; ~i; --i) { arr[i] = arr[i+1] + (s[i] == '0'); }
    orep(i, 1ul, s.size()) {
      if (!arr[i]) { s[i] = '1'; continue; }
      if (s[i] != '?') { continue; }
      if (s[i-1] == '0') { s[i] = '0'; }
      else { s[i] = '1'; }
    }
    std::cout << s; NL;
  }

  return 0;
}

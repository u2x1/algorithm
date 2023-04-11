#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, x; std::cin >> n >> x;
    std::string s; std::cin >> s;
    orep(i, 0ul, s.size()) {
      if (s[i] < x+'0') {
        std::cout << s.substr(0, i) << (char)(x+'0') << s.substr(i);
        goto fend;
      }
    }
    std::cout << s << (char)(x+'0');
fend:;
     NL;
  }
  return 0;
}

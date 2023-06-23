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
    int n; std::cin >> n;
    std::string s1, s2; std::cin >> s1 >> s2;
    auto cal = [](std::string s1, std::string s2) {
      int ret = 0;
      orep(i, 0ul, s1.size()) {
        ret += (s1[i] != s2[i]);
      }
      return ret;
    };
    int ans1 = 0;
    int a = cal(s1, s2);
    if (a & 1) {
      ans1 = a*2-1;
    } else {
      ans1 = a*2;
    }
    std::reverse(all(s1));

    int ans2 = 0;
    int b = cal(s1, s2);
    if (b & 1) {
      ans2 = b*2;
    } else {
      ans2 = b*2-1;
    }
    ans2 = std::max(2, ans2);
    std::cout << std::min(ans1, ans2); NL;
  }

  return 0;
}

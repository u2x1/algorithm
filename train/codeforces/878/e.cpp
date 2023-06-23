#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int _; std::cin >> _;
  while(_--) {
    std::string s1, s2; std::cin >> s1 >> s2;
    int t, q; std::cin >> t >> q;
    std::vector<char> eq(s1.size());
    auto eqcnt = 0ul;
    orep(i, 0ul, s1.size()) { eq[i] = s1[i] == s2[i]; eqcnt += eq[i]; }
    std::vector<std::pair<int, int>> wait; auto wc = 0ul;
    orep(nowt, 1, q+1) {
      int e; std::cin >> e;
      while(wait.size() && wc < wait.size() && wait[wc].first == nowt) {
        auto [__, p] = wait[wc++];
        if (!eq[p]) { --eqcnt; }
      }
      if (e == 1) {
        int p; std::cin >> p; --p;
        if (!eq[p]) { ++eqcnt; }
        wait.emplace_back(nowt+t, p);
      } else if (e == 2) {
        int f1, p1, f2, p2; std::cin >> f1 >> p1 >> f2 >> p2; --p1, --p2;
        char c1 = (f1 == 1 ? s1[p1] : s2[p1]);
        char c2 = (f2 == 1 ? s1[p2] : s2[p2]);
        char &rc1 = (f1 == 1 ? s1[p1] : s2[p1]);
        char &rc2 = (f2 == 1 ? s1[p2] : s2[p2]);
        rc1 = c2; rc2 = c1;
        if (eq[p1] != (s1[p1] == s2[p1])) {
          eqcnt += (s1[p1] == s2[p1])-eq[p1];
          eq[p1] = (s1[p1] == s2[p1]);
        }
        if (eq[p2] != (s1[p2] == s2[p2])) {
          eqcnt += (s1[p2] == s2[p2])-eq[p2];
          eq[p2] = (s1[p2] == s2[p2]);
        }
      } else {
        std::cout << (eqcnt == s1.size() ? "YES" : "NO"); NL;
      }
    }
  }

  return 0;
}

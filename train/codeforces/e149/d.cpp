#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::vector<int> l, r;
    int n; std::cin >> n;
    std::string s; std::cin >> s;

    orep(i, 0ul, s.size()) {
      auto x = s[i];
      x == '(' ? l.push_back(i) : r.push_back(i);
    }
    if (l.size() != r.size()) { std::cout << -1; NL; continue; }

    bool flag = 1;
    int stk = 0;
    for(auto x : s) {
      if (x == '(') { ++stk; continue; }
      --stk;
      if (stk < 0) { flag = 0; }
    }
    if (stk) { flag = 0; stk = 0; }
    if (flag) { std::cout << 1; NL; orep(i, 0, n) { std::cout << 1 << " "; } NL; continue; }
    flag = 1;
    std::reverse(s.begin(), s.end());
    for(auto x : s) {
      if (x == '(') { ++stk; continue; }
      --stk;
      if (stk < 0) { flag = 0; }
    }
    if (stk) { flag = 0; stk = 0; }
    if (flag) { std::cout << 1; NL; orep(i, 0, n) { std::cout << 1 << " "; } NL; continue; }
    std::reverse(s.begin(), s.end());

    std::vector<int> ret(n);
    orep(i, 0ul, (s.size()+1)/2) {
      ret[i] = s[i] == '(';
      if (ret[i]) {
        ret[r.back()] = 1;
        r.pop_back();
      } else {
        ret[l.back()] = 0;
        l.pop_back();
      }
    }
    std::cout << 2; NL;
    for(auto x : ret) { std::cout << x+1 << " "; } NL;
  }

  return 0;
}

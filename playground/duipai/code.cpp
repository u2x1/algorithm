#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {
    std::string s; std::cin >> s;
    bool ret = 1;
    std::string stk;
    std::vector<std::bitset<2>> q;
    std::bitset<2> st(0);
    for (auto c : s) {

      c = (c == '(' || c == ')');

      if (stk.size() && stk.back() == c) {
        st &= q.back();

        if (st[c]) { ret = 0; }

        q.pop_back();
        stk.pop_back();

        if (q.size()) {
          q.back() &= st;
        }

        st |= 1 << c;

      } else {
        stk += c;

        q.emplace_back(0b11);
      }
    }
    std::cout << (ret ? "Yes" : "No"); NL;
  }

  return 0;
}

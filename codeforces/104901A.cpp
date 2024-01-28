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
    bool ret = true;
    std::string stk; stk.reserve(s.size());
    std::vector<char> q;
    char st = 0;
    for (auto c : s) {

      c = (c == '(' || c == ')');

      if (stk.size() && stk.back() == c) {
        st = q.back();

        if (st >> c & 1) { ret = 0; break; }

        q.pop_back();
        stk.pop_back();

        st |= 1 << c;
      } else {
        stk += c;
        q.emplace_back(st);
        st = 0;
      }
    }

    std::cout << (ret ? "Yes" : "No"); NL;
  }

  return 0;
}

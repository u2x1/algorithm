#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int t; std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    std::vector<std::vector<int>> mp(n);
    for (int i = 0; i < n; ++i) {
      int x; std::cin >> x;
      mp[x].emplace_back(i);
    }
    for (int i = 0; i < n; ++i) {
      std::reverse(all(mp[i]));
    }
    std::vector<char> ret(n);
    for (char c = 'a'; c <= 'z'; ++c) {
      for (int i = 0; i < n; ++i) {
        if (mp[i].empty()) { break; }
        ret[mp[i].back()] = c;
        mp[i].pop_back();
      }
    }
    for (auto c : ret) { std::cout << c; } NL;
  }

  return 0;
}

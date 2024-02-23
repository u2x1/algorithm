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
    std::string s; std::cin >> s;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'B') {
        if (l == -1) { l = i; }
        r = i;
      }
    }
    std::cout << r - l + 1; NL;
  }

  return 0;
}

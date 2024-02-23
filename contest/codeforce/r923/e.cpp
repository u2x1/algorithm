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
    int n, k; std::cin >> n >> k;
    std::vector<int> ret(n);
    bool flag = 0;
    int pos = 0;
    int x = 1;
    while (x != n+1) {
      if (!flag) {
        for (; pos < n; pos += k) {
          if (pos < 0) { continue; }
          ret[pos] = x++;
        }
        pos++;
      } else {
        for (; pos > 0; pos -= k) {
          if (pos >= n) { continue; }
          ret[pos] = x++;
        }
        pos++;
      }
      flag ^= 1;
    }
    for (auto x : ret) { std::cout << x << " "; } NL;
  }

  return 0;
}

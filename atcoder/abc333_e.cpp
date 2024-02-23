#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::pair<int, int>> raw(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> raw[i].first >> raw[i].second;
  }
  std::vector<int> demand(n+1);
  std::vector<int> ret(n);
  int cnt = 0;
  for (int i = n - 1; i > -1; --i) {
    auto [a, b] = raw[i];
    if (a == 2) {
      demand[b] ++;
    } else {
      if (demand[b] > 0) {
        ret[i] = 1;
        demand[b] --;
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    if (demand[i]) { std::cout << -1; return 0; }
  }

  int ret1 = 0;
  for (int i = 0; i < n; ++i) {
    if (ret[i] == 1) {
      ++cnt;
    } else if (raw[i].first == 2) {
      --cnt;
    }
    ret1 = std::max(cnt, ret1);
  }
  std::cout << ret1; NL;

  for (int i = 0; i < n; ++i) {
    if (raw[i].first == 1) {
      std::cout << ret[i] << " ";
    }
  }

  return 0;
}

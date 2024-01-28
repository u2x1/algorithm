#include "bits/stdc++.h"

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int m, n; std::cin >> m >> n;
  std::vector<std::array<int, 3>> events;
  events.reserve(n+m/2);

  {
    int last = -1;
    for (int i = 0; i < m; i += 2) {
      int x, y; std::cin >> x >> y;
      events.push_back({x, last < y ? -1 : 1, y});
      last = y;
    }
  }

  for (int i = 0; i < n; ++i) {
    int x, y; std::cin >> x >> y;
    events.push_back({x, 0, y});
  }
  std::sort(all(events));

  int ret = 0;
  std::vector<std::pair<int, int>> slot;

  int height = 0;
  for (auto [_, o, y] : events) {
    if (o == 0) {
      if (slot.empty()) {
        ++ret;
        slot.emplace_back(y, height);
      } else {
        auto &[lo, hi] = slot.back();
        if (hi < y) {
          ++ret;
          slot.emplace_back(y, height);
        } else {
          lo = std::max(lo, y);
        }
      }
    } else {
      height = y;
      while (!slot.empty() && slot.back().first > y) { slot.pop_back(); }
      for (auto &x : slot) { x.second = std::min(x.second, y); }
    }
  }

  std::cout << ret;

  return 0;
}

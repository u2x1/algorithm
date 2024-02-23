#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::pair<int, int>> events;
  for (int i = 1; i <= n; ++i) {
    int a, b; std::cin >> a >> b;
    if (a > b) { std::swap(a, b); }
    events.push_back({a, i});
    events.push_back({b, -i});
  }
  std::vector<int> stk;
  std::sort(all(events));
  bool flag = true;
  for (int i = 0; i < 2*n; ++i) {
    auto [a, b] = events[i];
    if (b < 0) {
      if (stk.back() != -b) { flag = false; break; }
      else { stk.pop_back(); }
    } else {
      stk.emplace_back(b);
    }
  }
  std::cout << (!flag ? "Yes" : "No");

  return 0;
}

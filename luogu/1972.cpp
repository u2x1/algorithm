#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct BIT {
  std::vector<int> v; int n;
  BIT (int nn) : v(nn), n(nn) {}
  void upd(int p, int x) {
    for (++p; p <= n; p += (p & -p)) {
      v[p-1] += x;
    }
  }
  int qry(int p) {
    int ret = 0;
    for (; p > 0; p -= p & -p) {
      ret += v[p-1];
    }
    return ret;
  }
};

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> last(1e6+1, -1);
  std::vector<std::tuple<int, int, int, int>> events;
  for (int i = 0; i < n; ++i) {
    int x; std::cin >> x;
    if (~last[x]) { events.emplace_back(i, 0, last[x], inf); }
    events.emplace_back(i, 1, i, inf);
    last[x] = i;
  }
  int m; std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int l, r; std::cin >> l >> r; --l;
    events.emplace_back(r, -1, l, i);
  }
  std::sort(all(events));
  std::vector<int> ret(m);
  BIT bit(n+1);
  for (auto [r, o, l, idx] : events) {
    if (o == 0) { // remove
      bit.upd(l, -1);
    } else if (o == 1) { // add
      bit.upd(l, 1);
    } else {
      ret[idx] = bit.qry(r) - bit.qry(l);
    }
  }

  for (int i = 0; i < m; ++i) {
    std::cout << ret[i]; NL;
  }

  return 0;
}

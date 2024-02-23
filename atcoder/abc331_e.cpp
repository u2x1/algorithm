#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, m, l; std::cin >> n >> m >> l;
  std::vector<int> v1(n), v2(m);
  for (int i = 0; i < n; ++i) {
    std::cin >> v1[i];
  }
  for (int i = 0; i < m; ++i) {
    std::cin >> v2[i];
  }
  std::set<std::pair<int, int>> forbid;
  for (int i = 0; i < l; ++i) {
    int a, b; std::cin >> a >> b;
    --a, --b;
    forbid.emplace(a, b);
  }
  std::vector<int> i1(n), i2(m);
  std::iota(all(i1), 0);
  std::iota(all(i2), 0);
  std::sort(all(i1), [&](int a, int b) { return v1[a] > v1[b]; });
  std::sort(all(i2), [&](int a, int b) { return v2[a] > v2[b]; });
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (forbid.contains({i1[i], i2[j]})) { continue; }
      ret = std::max(v1[i1[i]] + v2[i2[j]], ret); break;
    }
  }
  std::cout << ret;

  return 0;
}

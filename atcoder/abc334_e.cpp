#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct DSU {
  std::vector<int> fa;
  DSU (int n) : fa(n) { std::iota(all(fa), 0); }
  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) { fa[find(y)] = find(x); }
};

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::string> mp(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> mp[i];
  }
  const int mo = 998244353;
  auto ksm = [&](lnt x, int e) -> int {
    lnt ret = 1;
    while (e) {
      if (e & 1) { ret = ret * x % mo; }
      x = x * x % mo; e >>= 1;
    }
    return ret;
  };
  auto inv = [&](int x) {
    return ksm(x, mo-2);
  };
  auto cord = [&](int x, int y) { return x * m + y; };
  DSU dsu(n*m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] != '#') { continue; }
      if (i && mp[i-1][j] == '#') { dsu.merge(cord(i-1, j), cord(i, j)); }
      if (j && mp[i][j-1] == '#') { dsu.merge(cord(i, j-1), cord(i, j)); }
    }
  }
  lnt raw = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] != '#') { continue; }
      raw += cord(i, j) == dsu.find(cord(i, j));
    }
  }
  lnt sum = 0;
  int div = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] != '.') { continue; }
      div ++;
      std::set<int> st;
      if (i && mp[i-1][j] == '#') { st.emplace(dsu.find(cord(i-1, j))); }
      if (j && mp[i][j-1] == '#') { st.emplace(dsu.find(cord(i, j-1))); }
      if (i != n-1 && mp[i+1][j] == '#') { st.emplace(dsu.find(cord(i+1, j))); }
      if (j != m-1 && mp[i][j+1] == '#') { st.emplace(dsu.find(cord(i, j+1))); }
      (sum += (raw + (1 - st.size()))) %= mo;
    }
  }
  std::cout << sum * inv(div) % mo;


  return 0;
}

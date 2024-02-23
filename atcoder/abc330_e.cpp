#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, q; std::cin >> n >> q;
  std::vector<int> v(n);
  std::map<int, int> mp;
  std::set<int> mex;
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
    mp[v[i]] ++;
    mex.emplace(i);
  }
  mex.emplace(n);
  for (auto [k, _] : mp) { mex.erase(k); }
  auto del = [&](int x) {
    if (--mp[x] == 0) {
      mex.emplace(x);
    }
  };
  auto add = [&](int x) {
    if (mp[x]++ == 0) {
      mex.erase(x);
    }
  };
  while (q--) {
    int i, x; std::cin >> i >> x;
    --i;
    del(v[i]);
    v[i] = x;
    add(v[i]);
    std::cout << *mex.begin(); NL;
  }

  return 0;
}

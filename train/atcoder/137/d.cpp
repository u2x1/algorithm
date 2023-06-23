#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::pair<int, int>> v(n);
  for(auto &x : v) { std::cin >> x.first >> x.second; }
  std::sort(all(v));
  long long ret = 0;
  std::priority_queue<int> q;
  int i = 0;
  orep(x, 1, m+1) {
    while(i < v.size() && v[i].first <= x) { q.emplace(v[i].second); ++i; }
    if (q.size()) { ret += q.top(); q.pop(); }
  }
  std::cout << ret;



  return 0;
}

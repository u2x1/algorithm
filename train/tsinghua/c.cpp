#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::vector<std::pair<int, int>> pre(3);
  for(int i = 0; i < 3; ++i) {
    std::cin >> pre[i].first >> pre[i].second;
  }
  int n; std::cin >> n;
  std::vector<int> v(n);
  for(auto &x : v) { std::cin >> x; }
  std::sort(all(v));
  std::sort(all(pre));
  std::vector<std::array<long long, 3>> sum(n+1);
  for(int i = 0; i < n; ++i) {
    sum[i+1][0] = std::abs(v[i]-pre[0].first)+sum[i][0];
    sum[i+1][1] = std::abs(v[i]-pre[1].first)+sum[i][1];
    sum[i+1][2] = std::abs(v[i]-pre[2].first)+sum[i][2];
  }
  const long long inf = 1e18;
  int divide = -1;
  for(int i = 1; i <= n; ++i) {
    if (sum[i][1]-sum[i-1][1] < sum[i][2]-sum[i-1][2]) { divide = i; }
  }
  long long ret = inf;
  for(int i = 0; i <= n; ++i) {
    long long cur = inf;
    if (i > pre[0].second) { break; }
    int l = std::max(i, n-pre[2].second);
    int r = std::min(i+pre[1].second, n);
    if (l > r) { continue; }
    // std::cout << i << " "<< l << " " << r; NL;
    // std::cout << divide; NL;
    int x = (l <= divide && divide <= r) ? divide : (r < divide ? r : l);
    cur = sum[i][0] + sum[x][1]-sum[i][1] + sum[n][2]-sum[x][2];
    // std::cout << i << " " << x << " " << cur; NL;
    ret = std::min(ret, cur);
  }
  std::cout << ret;

  return 0;
}

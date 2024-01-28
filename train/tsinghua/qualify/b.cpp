#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, m, k; std::cin >> n >> m >> k;
  std::vector<int> v(n);
  for(auto & x  : v) { std::cin >> x; }
  std::vector<long long> sum(n+5);
  orep(i, 0, m) {
    int l, r; std::cin >> l >> r;
    --l, --r;
    sum[l]++; sum[r+1]--;
  }
  std::vector<std::pair<long long, long long>> prs;
  orep(i, 0, n) {
    sum[i] += (i ? sum[i-1] : 0);
    if (sum[i]) {
      prs.push_back({sum[i], v[i]});
    }
  }
  std::sort(prs.rbegin(), prs.rend());
  long long ret = 0;
  for(auto [x, y] : prs) {
    if (k) {
      long long a = std::min(k, y);
      k -= a; y -= a;
    }
    ret += x * y;
  }
  std::cout << ret;

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << std::endl;

using i64 = long long;

const int maxN = 5e5+5;
std::vector<i64> a;
std::pair<i64, int> mx[maxN][20];
i64 _sum[maxN]; i64 sum(int l, int r) { return _sum[r-1]-_sum[l-1]; }

i64 find(const int l, const int r) {
  const int k = std::__lg(r-l);
  return std::max(mx[l][k], mx[r-(1<<k)][k]).second;
};

const i64 INF = 1ll<<60;
i64 ans(const int l, const int r) {
  if (l == r-1) { return a[l]; }
  const int m = find(l, r);
  i64 ret = INF;
  if (l < m) {
    const i64 lans = ans(l, m);
    ret = std::min(ret, lans+std::max(0ll, a[m]-(sum(l, m)+lans)));
  }
  if (r-1 > m) {
    const i64 rans = ans(m+1, r);
    ret = std::min(ret, rans+std::max(0ll, a[m]-(sum(m+1, r)+rans)));
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<i64> tmp(n);
  orep(i, 0, n) { std::cin >> tmp[i]; } 
  a.emplace_back(0);
  a.insert(a.end(), std::max_element(tmp.begin(), tmp.end()), tmp.end());
  a.insert(a.end(), tmp.begin(), std::max_element(tmp.begin(), tmp.end()));
  orep(i, 1, n+1) { _sum[i] = a[i] + _sum[i-1]; mx[i][0] = {a[i], i}; }
  orep(k, 1, 20) {
    for(int i = 1; i+(1<<k)-1 <= n; ++i) {
      mx[i][k] = std::max(mx[i][k-1], mx[i+(1<<(k-1))][k-1]);
    }
  }
  
  std::cout << ans(1, n+1);

  return 0;
}

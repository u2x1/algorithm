#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

struct Fenwick {
  std::vector<int> v; int n;
  Fenwick(int x) : v(x+1), n(x) {}
  void add(int p, int x) {
    while(p <= n) {
      v[p] += x;
      p += (p&-p);
    }
  }
  int get(int p) {
    int ret = 0;
    while(p) {
      ret += v[p];
      p -= (p&-p);
    }
    return ret;
  }
};
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<long long> sum(n);
  std::vector<long long> val;
  orep(i, 0, n) {
    int x; std::cin >> x;
    sum[i] = x + (i ? sum[i-1] : 0); val.emplace_back(sum[i]);
    if (sum[i] < 0) { std::cout << -1; return 0; }
  }
  if (*std::max_element(all(sum)) != sum.back()) { std::cout << -1; return 0; }
  std::sort(all(val));
  val.erase(std::unique(all(val)), val.end());
  auto idx = [&](long long x) { return std::upper_bound(all(val), x) - val.begin(); };
  long long ret = 0;
  Fenwick v(val.size());
  orep(i, 0, n) {
    ret += v.get(val.size()) - v.get(idx(sum[i]));
//    std::cout << sum[i] << " " << idx(sum[i]); NL;
    v.add(idx(sum[i]), 1);
  }
  std::cout << ret;

  return 0;
}

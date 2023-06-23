#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

struct BIT {
  std::vector<int> v; int n;
  BIT(int _) : v(_), n(_) {}
  void add(int p, int x) {
    while(p <= n) {
      v[p] += x;
      p += (p & -p);
    }
  }
  int get(int p) {
    int ret = 0;;
    while(p) { ret += v[p]; p -= (p & -p); }
    return ret;
  }
};

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::pair<int, int>> seg;
  std::vector<int> val;
  orep(i, 0, n) {
    int e, a, b; std::cin >> e >> a >> b;
    a *= 2, b *= 2;
    if (e == 1) {
      seg.emplace_back(a, b);
      val.emplace_back(a);
      val.emplace_back(b);
    } else if (e == 2) {
      seg.emplace_back(a, b-1);
      val.emplace_back(a);
      val.emplace_back(b-1);
    } else if (e == 3) {
      seg.emplace_back(a+1, b);
      val.emplace_back(a+1);
      val.emplace_back(b);
    } else if (e == 4) {
      seg.emplace_back(a+1, b-1);
      val.emplace_back(a+1);
      val.emplace_back(b-1);
    }
  }
  std::sort(all(seg), [](auto a, auto b) { return a.second < b.second; });
  std::sort(all(val)); val.erase(std::unique(all(val)), val.end());
  auto idx = [&](int x) { return std::upper_bound(all(val), x) - val.begin(); };
  BIT sum(val.size()+5);
  long long ret = 0;
  for(auto [fl, fr] : seg) {
    int l = idx(fl), r = idx(fr);
    ret += sum.get(r-1) - sum.get(l-1);
    sum.add(r, 1);
  }
  orep(i, 0, n) {
    int r = seg[i].second;
    long long cnt = 0;
    while(i < n && seg[i].second == r) { ++i; ++cnt; } --i;
    ret += cnt * (cnt-1) / 2;
  }
  std::cout << ret;

  return 0;
}

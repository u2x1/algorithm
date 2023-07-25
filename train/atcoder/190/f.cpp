#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

struct BIT {
  std::vector<long long> v; int n;

  BIT(int x) : v(x+5), n(x+5) {}

  void add(int pos, int x) {
    ++pos;
    while(pos <= n) {
      v[pos-1] += x;
      pos += pos & -pos;
    }
  }

  long long sum(int pos) {
    ++pos;
    int ret = 0;
    while(pos > 0) {
      ret += v[pos-1];
      pos -= pos & -pos;
    }
    return ret;
  }
};

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  BIT t(n);
  std::vector<int> cnt(n+1);
  std::vector<int> v(n);
  long long ret = 0;
  for(auto &x : v) {
    std::cin >> x;
    t.add(x, 1);
    ret += t.sum(n) - t.sum(x);
  }
  std::cout << ret; NL;
  orep(i, 0, n-1) {
    ret += n-v[i]-1 - v[i];
    std::cout << ret; NL;
  }

  return 0;
}

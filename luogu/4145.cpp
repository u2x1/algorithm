#include <iostream>
#include <cmath>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

using i64 = long long;
const int maxN = 2e5+5;
i64 t[maxN], n;

i64 ask(int x) {
  i64 ret = 0;
  while(x > 0) {
    ret += t[x];
    x -= x&-x;
  }
  return ret;
}

void add(int x, i64 val) {
  while(x <= n) {
    t[x] += val;
    x += x&-x;
  }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n;
  std::set<int> idx;
  i64 tmp;
  orep(i, 1, n+1) {
    std::cin >> tmp;
    add(i, tmp);
    if (tmp > 1) { idx.insert(i); }
  }
  int m; std::cin >> m;
  orep(i, 0, m) {
    int e, l, r; std::cin >> e >> l >> r;
    if (l > r) { std::swap(l, r); }
    if (e) {
      std::cout << ask(r) - ask(l-1); NL;
    } else {
      auto fst = idx.lower_bound(l);
      if (fst == idx.end() || *fst > r) { continue; }
      auto fnl = fst;
      while(fnl != idx.end() && *fnl <= r) {
        i64 val = ask(*fnl) - ask((*fnl)-1);
        i64 target = sqrtl(val);
        add(*fnl, target-val);
        if (target <= 1) { idx.erase(fnl++); }
        else { ++fnl; }
      }
    }
  }

  return 0;
}

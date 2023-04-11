#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'
#define int long long

const int maxN = 2e2+5;
struct st { int fen, shi, cuo; } ti[maxN];

inline int cal(const int i, const int t) {
  const int ret = ti[i].fen - ti[i].fen*0.004*t - 50*ti[i].cuo;
  return std::max(ret, (int)(ti[i].fen*0.3));
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, m; std::cin >> n >> m;
    std::vector<int> p;
    orep(i, 0, n) { std::cin >> ti[i].fen >> ti[i].shi >> ti[i].cuo; p.push_back(i); }
    int ret = 0;
    do {
      int cur = 0;
      int tt = 0;
      for(const auto x:p) {
        tt += ti[x].shi;
        if (tt > m) { break; }
        cur += cal(x, tt);
      }
      ret = std::max(ret, cur);
    }
    while (std::next_permutation(p.begin(), p.end()));
    std::cout << ret; NL;
  }

  return 0;
}

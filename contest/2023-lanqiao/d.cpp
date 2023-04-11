#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i, a, b) for(auto i = (a); i < (b); ++i)
#define NL std::cout << '\n'

const int maxN = 2e5+5;
struct st {
  int t, d, l;
} a[maxN];

struct range {
  int l, r;
};

const int INF = 1e9;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> per;
    orep(i, 0, n) {
      std::cin >> a[i].t >> a[i].d >> a[i].l;
      per.emplace_back(i);
    }
    do {
      std::vector<range> rs { {0, INF} };
      bool pass = 1;
      orep(j, 0, n) {
        const auto &x = a[per[j]];
        bool bad = 1;
        orep(i, 0ul, rs.size()) {
          if (x.t <= rs[i].l && x.t+x.d >= rs[i].l && rs[i].l+x.l <= rs[i].r) {
            rs.push_back({rs[i].l+x.l, rs[i].r});
            rs.push_back({rs[i].l, x.l});
            rs[i].l = rs[i].r = -1;
            bad = 0; break;
          }
        }
        if (bad) { pass = 0; break; }
      }
      if (pass) {
        std::cout << "YES"; goto fend;
      }
    }
    while(std::next_permutation(per.begin(), per.end()));
    std::cout << "NO";
    fend: NL;
  }
	return 0;
}

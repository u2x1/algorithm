#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int a[maxN];
struct st { long long val; int pos; };
bool operator<(const st &c, const st &b) { return (c.val == b.val ? c.pos > b.pos : c.val < b.val); }
std::map<long long, std::vector<st>> mp;
std::map<long long, int> poss;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    mp.clear();
    poss.clear();
    int n, m; std::cin >> n >> m;
    long long c = 0;
    orep(i, 1, n+1) {
      std::cin >> a[i]; c += a[i]; 
    }
    bool md = 0;
    if (c < 0) { orep(i, 1, n+1) { a[i] = -a[i]; } c = -c; md = 1; }
    long long sum = 0;
    orep(i, 1, n+1) {
      sum += a[i];
      if (!c) { if (!poss[sum]) { poss[sum] = i; } }
      else {
        const long long cur = (sum%c + c) % c;
        if (mp.find(cur) == mp.end()) { mp[cur] = std::vector<st>(); }
        mp[cur].push_back({sum, i});
      }
    }
    for(auto &[_, v] : mp) { std::sort(v.begin(), v.end()); }
    orep(i, 0, m) {
      long long q; std::cin >> q; if (md) { q = -q; }
      if (!q) { std::cout << 0; NL; continue; }
      if (!c) { std::cout << (poss[q] ? poss[q] : -1); NL; continue; }
      const long long x = (q%c + c) % c;
      const auto it = mp.find(x);
      if (it == mp.end()) { std::cout << -1; NL; continue; }
      const auto qq = st {q, 0};
      const auto itt = std::upper_bound(it->second.begin(), it->second.end(), qq);
      if (itt == it->second.begin() || (itt-1)->val > q) { std::cout << -1; NL; continue; }
      const auto &got = *(itt-1);
      std::cout << (q - got.val) / c * n + got.pos; NL;
    }
  }

  return 0;
}

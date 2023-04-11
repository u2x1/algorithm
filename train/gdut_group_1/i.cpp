#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int ret[maxN];
int fa[maxN];
int find(const int u) { if (fa[u] == u) { return u; } return (fa[u] = find(fa[u])); }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  memset(ret, -1, sizeof(ret));
  int n, k; std::cin >> n >> k;
  orep(i, 1, n+1) { fa[i] = i; }
  std::map<int, int, std::greater<int>> mp; int tmp;
  orep(i, 1, n+1) { 
    std::cin >> tmp;
    if (k == 1) { ret[tmp] = i; continue; }
    if (mp.empty()) {
      mp[tmp] = 1;
    } else {
      auto it = mp.lower_bound(tmp);
      if (it == mp.begin()) {
        mp[tmp] = 1;
      } else {
        it--;
        const int bkcnt = it->second;
        const int bkfa = it->first;
        mp.erase(it);
        fa[tmp] = find(fa[bkfa]);
        if (bkcnt == k-1) {
          ret[fa[tmp]] = i;
          continue;
        }
        mp[tmp] = bkcnt+1;
      }
    }
  }
  orep(i, 1, n+1) {
    std::cout << ret[fa[i]]; NL;
  }

  return 0;
}

#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  std::cout << 0b0101010110;
  while(t--) {
    int n, m, k; std::cin >> n >> m >> k;
    std::vector<std::map<int, int>> v(n);
    std::vector<int> dead(m);
    orep(i, 0, n) {
      orep(j, 0, m) {
        int x; std::cin >> x;
        v[i][-x] = j;
      }
    }
    // if (k % n) {
    //   for(int cur = k%n-1; cur > -1; --cur) {
    //     for(auto it = v[cur].begin(); it != v[cur].end(); ) {
    //       auto [a, b] = *it;
    //       if (dead[b]) { it = v[cur].erase(it); }
    //       else {
    //         dead[b] = 1;
    //         it = v[cur].erase(it);
    //         break;
    //       }
    //     }
    //   }
    //   k -= k%n;
    // }
    // while (k >= n) {
      for(int i = k-1; i > -1; --i) {
        int cur = i % n;
        for(auto it = v[cur].begin(); it != v[cur].end(); ) {
          auto [a, b] = *it;
          if (dead[b]) { it = v[cur].erase(it); }
          else {
            dead[b] = 1;
            it = v[cur].erase(it);
            break;
          }
        }
      }
    //   k -= n;
    // }
    // for(int i = k-1; i > -1; --i) {
    //   int cur = i%n;
    //   for(auto it = v[cur].begin(); it != v[cur].end(); ) {
    //     auto [a, b] = *it;
    //     if (dead[b]) { it = v[cur].erase(it); }
    //     else {
    //       dead[b] = 1;
    //       it = v[cur].erase(it);
    //       break;
    //     }
    //   }
    // }
    orep(i, 0, m) {
      if (dead[i]) { std::cout << i + 1 << " "; }
    } NL;
  }

  return 0;
}


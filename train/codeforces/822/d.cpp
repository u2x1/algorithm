#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'
#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, k; std::cin >> n >> k;
    std::vector<int> v(n+1);
    orep(i, 1, n+1) { std::cin >> v[i]; }
    for(int i = k-1; i > 1; --i) { v[i-1] += v[i]; }
    for(int i = k+1; i < n; ++i) { v[i+1] += v[i]; }
    // for(auto x : v) { std::cout << x << " " ; } NL;
    int lmax = 0, rmax = 0;
    int vk = v[k]; v[k] = 0;
    int l = k, r = k;
    while(l > 0 || r < n+1) {
      int rawl = l, rawr = r;
      for(; l > 0 && v[l] + rmax + vk >= 0; --l) {
        lmax = std::max(lmax, v[l]);
        // std::cout << l << ": " << v[l] + rmax + vk; NL;
      }
      for(; r < n+1 && v[r] + lmax + vk >= 0; ++r) {
        rmax = std::max(rmax, v[r]);
        // std::cout << r << ": " << v[r] + lmax + vk; NL;
      }
      // std::cout << l << " " << r; NL;
      if (rawl == l && rawr == r) { break; }
    }
    std::cout << (l == 0 || r == n+1 ? "YES" : "NO"); NL;
  }

  return 0;
}

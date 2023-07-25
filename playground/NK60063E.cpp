#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int mod = 1e9+7;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<int> s1(m+1), s2(m+1);
  orep(i, 1, m+1) { s1[i] = s1[i-1] + 1; }
  orep(i, 2, n+1) {
    // orep(i, 0, m+1) { std::cout << t1.get(i) - t1.get(i-1) << " "; } NL;
    orep(j, 1, m+1) {
      int x = i*j;
      int r = (x-1)/(i-1), l = (std::max(0, x-m)-1) / (i-1);
      // std::cerr << x << " " << l << " " << r << std::endl;
      int val;
      if (r <= l) { val = 0; }
      else {
        if (r > m) { r = m; }
        if (l < 0) { l = 0; }
        val = (s1[r]-s1[l]) % mod;
      }
      s2[j] = (s2[j-1] + val) % mod;
    }
    std::swap(s1, s2); std::fill(all(s2), 0);
  }
  std::cout << (s1[m]+mod)%mod;

  return 0;
}

#include <iostream>
#include <string>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;

using ui64 = unsigned long long;
ui64 f[maxN], g[maxN], h[maxN], px[maxN], pxx[maxN], pxxx[maxN];
ui64 X = 131, XX = 1331, XXX = 133331;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  px[0] = pxx[0] = pxxx[0] = 1;
  orep(i, 1, maxN) { px[i] = px[i-1] * X; }
  orep(i, 1, maxN) { pxx[i] = pxx[i-1] * XX; }
  orep(i, 1, maxN) { pxxx[i] = pxxx[i-1] * XXX; }
  std::string s; std::cin >> s;
  orep(i, 1ul, s.size()+1) {
    f[i] = f[i-1]*X+s[i-1];
    // std::cout << f[i] - f[i-1]*X ; NL;
    g[i] = g[i-1]*XX+s[i-1];
    h[i] = h[i-1]*XXX+s[i-1];
  }
  orep(i, 1ul, s.size()) {
    if (f[i] == f[s.size()] - f[s.size()-i] * px[i]) {
       if (g[i] == g[s.size()] - g[s.size()-i] * pxx[i]) {
         if (h[i] == h[s.size()] - h[s.size()-i] * pxxx[i]) {
          std::cout << "Wrong Answer"; exit(0);
         }
       }
    }
  }
  std::cout << "Correct";
  return 0;
}

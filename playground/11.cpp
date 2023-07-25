#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  std::vector<int> ret(500000);

  { // INIT
    int o = -1, i = 1;
    ++o; orep(j, 0, 2) { ret[i++] = o; }
    ++o; orep(j, 0, 2) { ret[i++] = o; }
    ++o; orep(j, 0, 3) { ret[i++] = o; }
    ++o; orep(j, 0, 3) { ret[i++] = o; }
    ++o; orep(j, 0, 2) { ret[i++] = o; }
    ++o; orep(j, 0, 3) { ret[i++] = o; }
    ++o; orep(j, 0, 3) { ret[i++] = o; }

    for(; i < 200000; ) {
      ++o; orep(j, 0, 2) { ret[i++] = o; }
      ++o; orep(j, 0, 3) { ret[i++] = o; }
      ++o; orep(j, 0, 3) { ret[i++] = o; }
      ++o; orep(j, 0, 3) { ret[i++] = o; }
      ++o; orep(j, 0, 2) { ret[i++] = o; }
      ++o; orep(j, 0, 3) { ret[i++] = o; }
      ++o; orep(j, 0, 3) { ret[i++] = o; }
    }
  }
  orep(i, 9000, 9004) {
    // std::cout << i << " " << ret[i] << " " << ret[i]*3 << " " << 1.0*i/ret[i]; NL;
    std::cout << i << " " << (i / 2.718281828459045); NL;
    // std::cout << (i / 2.71828L); NL;
  }

  orep(i, 1, 10) { method1(i); }
  // while(t--) {
  //   int n; std::cin >> n;
  //   std::cout << ret[n]; NL;
  // }

  return 0;
}

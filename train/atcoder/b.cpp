#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int a, b, c, d; std::cin >> a >> b >> c >> d;
  std::cout << (c*d<=b ? -1 : (a+c*d-b-1)/(c*d-b));


  return 0;
}

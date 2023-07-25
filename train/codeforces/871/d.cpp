#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

bool check(int a, int b) {
  if (a < b) { return 0; }
  if (a == b) { return 1; }
  if (a % 3) { return 0; }
  return check(a/3*2, b) || check(a/3, b);
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int a, b; std::cin >> a >> b;
    std::cout << (check(a, b) ? "YES" : "NO"); NL;
  }
    

  return 0;
}

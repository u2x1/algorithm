#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'


bool check(int x ){ 
  if (x % 3 == 0) { return 0; }
  return (x % 10) != 3;
}
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::vector<int> v { 0 };
  int x = 1;
  orep(i, 1, 3000) {
    while(!check(x)) { ++x; }
    v.emplace_back(x++);
  }
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::cout << v[n]; NL;
  }

  return 0;
}

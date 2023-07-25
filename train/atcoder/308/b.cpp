#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::vector<int> v(8);
  for(auto &x : v) { std::cin >> x; if (x < 100 || x > 675 || x % 25) { std::cout << "No"; exit(0); } }
  orep(i, 1, 8) { if (v[i] < v[i-1]) { std::cout << "No"; exit(0); } }
  std::cout << "Yes";
  return 0;
}

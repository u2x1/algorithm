#include <iostream>
#include <vector>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q; std::cin >> n >> q;
  std::vector<std::multiset<int>> box(n+1);
  std::vector<std::set<int>> num(maxN);
  orep(i, 0, q) {
    int e; std::cin >> e;
    if (e == 1) {
      int a, b; std::cin >> a >> b;
      box[b].insert(a);
      num[a].insert(b);
    } else if (e == 2) {
      int a; std::cin >> a;
      for(auto x : box[a]) { std::cout << x << " "; } NL;
    } else if (e == 3) {
      int a; std::cin >> a;
      for(auto x : num[a]) { std::cout << x << " "; } NL;
    }
  }

  return 0;
}

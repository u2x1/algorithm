#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int _; std::cin >> _;
  while(_--) {
    int n; std::cin >> n;
    if (n == 1) { std::cout << 1; NL; continue; }
    if (n & 1) { std::cout << -1; NL; continue; }
    std::vector<int> v(n);
    {
      int x = 1;
      orep(i, 0, n) {
        v[i] = x++; ++i;
      }
      for(int i = n-1; i > 0; --i) {
        v[i] = x++; --i;
      }
    }
    std::vector<int> ret(n);
    ret[0] = n;
    orep(i, 1, n) {
      ret[i] = (v[i]-v[i-1]+n) % n;
    }
    for(auto x : ret) { std::cout << x << " "; } NL;
  }

  return 0;
}

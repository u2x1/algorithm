#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int a[maxN], b[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int _; std::cin >> _;
  while(_--) {
    int n, t; std::cin >> n >> t;
    orep(i, 0, n) { std::cin >> a[i]; }
    orep(i, 0, n) { std::cin >> b[i]; }
    int ret = -1; int mx= 0;
    orep(i, 0, n) {
      if (t < a[i]) { --t; continue; }
      if (mx < b[i]) {
        ret = i+1; mx = b[i];
      }
      --t;
    }
    std::cout << ret; NL;
  }

  return 0;
}

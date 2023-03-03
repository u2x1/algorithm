#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;

  std::map<int, int> arr{{n+1, 0}, {0, 0}};
  long long sum = 0;
  orep(i, 1, n+1) {
    int tmp; std::cin >> tmp;
    arr[i] = tmp;
    sum += arr[i];
  }

  orep(i, 0, m) {
    int op; std::cin >> op;
    if (op == 1) {
      int l, r, k; std::cin >> l >> r >> k;
      for(auto it = arr.lower_bound(l); it->first <= r; it++) {
        orep(j, 0, k) {
          int tt = round(10*sqrtl(it->second));
          sum = sum - it->second + tt;
          it->second = tt;
          if (tt == 100 || tt == 0 || tt == 99) { it = arr.erase(it); it--; break; }
        }
      }
    } else {
      std::cout << sum; NL;
    }
  }

  return 0;
}

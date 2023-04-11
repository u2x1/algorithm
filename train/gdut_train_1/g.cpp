#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'
#define int long long

const int maxN = 2e6+5;
int arr[maxN];
int q[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    int l = 0, r = 0;
    orep(i, 0, n) { std::cin >> arr[i]; if (!arr[i]) { q[r++] = i; arr[i] = -1; } }
    int one = 0;
    int ret1 = 1, ret2; int g;
    orep(i, 0, n) {
      if (arr[i] == -1 && !one && (l==r || q[l] > i)) {
        std::cout << -1; goto fend;
      } else if (arr[i] == 1) {
        ++one;
        ++ret1;
      } else if (arr[i] == -1) {
        if (one) { --one; }
        else {
          ++l;
          ++one;
          ++ret1;
        }
      }
    }
    ret2 = ret1 - (n+1-ret1);
    g = std::__gcd(ret1, ret2);
    ret1 /= g; ret2 /= g;
    std::cout << ret1 << " " << ret2;

fend:; NL;
  }

  return 0;
}

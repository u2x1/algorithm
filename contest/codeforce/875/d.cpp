#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

struct node { long long a, b; };
bool operator<(const node &a, const node &b) { return a.a > b.a; }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<node> nd(n);
    long long ret = 0;
    orep(i, 0, n) { std::cin >> nd[i].a; }
    orep(i, 0, n) { std::cin >> nd[i].b; }
    std::sort(nd.begin(), nd.end());
    for(int x = 1; x*x <= 2*n; ++x) {
      std::vector<int> cnt(2*n);
      for(auto [a, b] : nd) {
        if (a < x) { break; }
        if (a == x) { ret += cnt[b]; }
        if (x*a-b > 0 && x*a-b <= n) { cnt[x*a-b]++; }
        // std::cout << a << " " << b; NL;
      }
    }
    std::cout << ret; NL;
  }

  return 0;
}

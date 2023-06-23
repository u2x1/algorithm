#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; int n; std::cin >> n >> s;
  bool wtf = 1;
  int conti = 0;
  int mx = 0;
  for(auto x : s) {
    if (x == '-') {
      mx = std::max(mx, conti);
      conti = 0;
      wtf = 0;
    }
    if (x == 'o') { ++conti; }
  }
  mx = std::max(mx, conti);
  std::cout << (wtf || !mx ? -1 : mx);

  return 0;
}

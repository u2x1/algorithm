#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k; std::cin >> n >> m >> k;
  int cnt = 0, tmp;
  bool exist = 0;
  orep(i, 0, n) {
    std::cin >> tmp;
    if (tmp > m) { cnt++; }
    if (tmp == m) { exist = 1; }
  }
  if (!exist && !cnt) { k--; }
  k -= cnt;
  std::cout << (k >= 0 ? "YES" : "NO");

  return 0;
}

#include <iostream>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int cnt[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  int tmp;
  while(t--) {
    memset(cnt, 0, sizeof(cnt));
    int n; std::cin >> n;
    orep(i, 0, n) {
      std::cin >> tmp; cnt[tmp]++;
    }
    int ret = 0;
    orep(i, 1, n) { ret = std::max(ret, cnt[i]); }
    orep(i, 1, n-1) {
      ret = std::max(ret, (cnt[i] >= 1 ? 1 : 0) + cnt[i+1]);
    }
    std::cout << n-ret; NL;
  }

  return 0;
}

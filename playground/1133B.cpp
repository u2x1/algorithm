#include <iostream>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  std::vector<int> cnt(k+1);
  orep(i, 0, n) { int x; std::cin >> x; x %= k; cnt[x]++; }
  int ret = 0;
  orep(i, 0, k) {
    if (!i) { ret += cnt[i]/2*2; continue; }
    if (i+i == k) { ret += cnt[i]/2*2; continue; }
    int x = std::min(cnt[i], cnt[k-i]);
    cnt[i] -= x;
    cnt[k-i] -= x;
    ret += x*2;
  }
  std::cout << ret;


  return 0;
}

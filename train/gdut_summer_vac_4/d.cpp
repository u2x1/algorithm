#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e7+5;
int arr[maxN];

int prime[maxN]; int cnt;
int mp[maxN];
void init() {
  orep(i, 2, maxN) {
    if(!mp[i]) { mp[i] = i; prime[cnt++] = i; }
    for(int j = 0; i*prime[j] < maxN; ++j) {
      mp[i*prime[j]] = prime[j];
      if (i % prime[j] == 0) { break; }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  init();
  int t; std::cin >> t;
  while(t--) {
    int a, b; std::cin >> a >> b;
    int w = b-a;
    if (w == 1) { std::cout << -1; NL; continue; }
    int ret = (1<<30)-1;
    while (w > 1) {
      int p = mp[w];
      w/=p;
      ret = std::min(ret, (p-a%p)%p);
    }
    std::cout << ret; NL;
  }

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
long long cnta[maxN], cntb[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n; std::vector<int> a(n), b(n), c(n);
  orep(i, 0, n) { std::cin >> a[i]; }
  orep(i, 0, n) { std::cin >> b[i]; }
  std::vector<int> nb;
  orep(i, 0, n) { std::cin >> c[i]; if (c[i] <= n) { nb.push_back(b[c[i]-1]); } }
  orep(i, 0, n) { cnta[a[i]]++; }
  for(auto x : nb) { cntb[x]++; }
  long long ret = 0;
  orep(i, 1, maxN) { ret += cnta[i]*cntb[i]; } 
  std::cout << ret;


  return 0;
}

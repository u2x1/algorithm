#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
struct st { int sugar, water; } as[maxN], bs[maxN];
long long n, m, k;

const long double eps = 1e-15;

long double a[maxN], b[maxN];

long long bigger() {
  long long ret = 0;
  for(long long l = 0, r = 0; l < n; ++l) {
    while(r < m && a[l] >= b[r]) { ++r; }
    ret += r;
  }
  return ret;
}

signed main() {
  std::cin >> n >> m >> k;
  orep(i, 0, n) { std::cin >> as[i].sugar >> as[i].water; }
  orep(i, 0, m) { std::cin >> bs[i].sugar >> bs[i].water; }

  long double l = 0, r = 1;
  while(l<r-eps) {
    const long double mid = (r+l)/2;
    orep(i, 0, n) { a[i] = as[i].sugar - mid*(as[i].sugar + as[i].water); }
    orep(i, 0, m) { b[i] = mid*(bs[i].sugar + bs[i].water) - bs[i].sugar; }
    std::sort(a, a+n); std::sort(b, b+m);
    if (bigger() >= k) { l = mid; }
    else { r = mid; }
  }
  printf("%.15Lf", l*100);


  return 0;
}

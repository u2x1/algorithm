#include <iostream>

#define orep(i, a, b) for(int i = (a); i < (b); ++i)
#define NL std::cout << '\n'
#define int long long 
const int maxN = 2e5+5;
int a[maxN], b[maxN];

int n;
int check(const int x) {
  orep(i, 0, n) {
    if (a[i]/x > b[i]) {
      return 1;
    } else if (a[i]/x < b[i]) {
      return -1;
    }
  }
  return 0;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n;
  orep(i, 0, n) {
    std::cin >> a[i] >> b[i];
  }
  
  int l = -1, r = 1e9+1;
  while(l < r) {
    const int m = (l+r) >> 1;
    const int ret = check(m);
    if (ret > 0) {
      l = m+1;
    } else {
      r = m;
    }
  }
  std::cout << r << " "; 
  l = -1, r = 1e9+1;
  while(l < r) {
    const int m = (l+r) >> 1;
    const int ret = check(m+1);
    if (ret >= 0) {
      l = m+1;
    } else {
      r = m;
    }
  }
  std::cout << l;
  return 0;
}

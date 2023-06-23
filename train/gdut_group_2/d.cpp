#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];


int prime[maxN]; bool notPrime[maxN];
int cnt;

int f(int x) {
  for(int j = x+1; ;++j) {
    if (!notPrime[j]) { return j; }
  }
}

int g(int x) {
  return (f(x) + f(f(x))) / 2;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
   prime[cnt++] = 2;
   orep(i, 2, 10000) {
     if (!notPrime[i]) {
       prime[cnt++] = i;
       for(int j = i+i; j < maxN; j += i) {
         notPrime[j] = 1;
       }
     }
   }
   orep(i, 1, 10) { std::cout << cnt; NL; }
  int t; std::cin >> t;
  while(t--) {
    long long n; std::cin >> n;
    std::cout << (n == 1 ? "YES" : "NO"); NL;
  }

  return 0;
}

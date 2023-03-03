#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int p = 1000000007;
const int maxN = 1e6+5;
long long frac[maxN];

long long inv(long long a) {
  int e = p-2;
  long long ret = 1;
  while(e) {
    if (e&1) { ret = (ret*a)%p; }
    e/=2; a = a*a%p;
  }
  return ret;
}

long long c(int m, int n) {
  return frac[m] * inv(frac[m-n]) % p * inv(frac[n]) % p;
}

bool good(int a, int b, int x) {
  while(x) {
    if (x%10 != a && x%10 != b) { return 0; }
    x /= 10;
  }
  return 1;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int a, b, n; std::cin >> a >> b >> n;
  frac[0] = frac[1] = 1;
  orep(i, 2, n+1) { frac[i] = frac[i-1]*i%p; }
  long long ret = 0;
  orep(i, 0, n+1) {
    const int x = a*i+b*(n-i);
    // std::cout << c(1, 1); NL;
    if (good(a, b, x)) { ret = (ret+c(n, i)) % p; }
  }
  std::cout << ret;

  return 0;
}

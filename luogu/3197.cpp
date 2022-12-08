#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
const int mod = 1e5+3;
int arr[maxN];

long long ksm(long long exp, long long base) {
  long long ret = 1;
  while(exp) {
    if (exp%2) {
      ret = (ret * base) % mod;
      --exp;
    } else {
      base = (base * base) % mod;
      exp /= 2;
    }
  }
  return ret;
}

int main() {
  long long m, n; scanf("%lld%lld", &m, &n);
  if (n==1) { printf("0"); return 0; }
  long long all = ksm(n, m);
  long long minus = (m * ksm(n-1, m-1))%mod;
  printf("%lld", (all-minus+mod)%mod);
  return 0;
}

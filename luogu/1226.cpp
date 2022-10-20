#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

long long a, b, p;

long long ksm(long long x, long long exp) {
  long long ret = 1;
  while(exp) {
    if (exp & 1) {
      ret = (ret * x) % p;
      --exp; continue;
    }
    x = (x*x) % p;
    exp >>= 1;
  }
  return ret;
}

int main() {
  scanf("%lld%lld%lld", &a, &b, &p);
  printf("%lld^%lld mod %lld=%lld", a, b, p, ksm(a, b));

  return 0;
}

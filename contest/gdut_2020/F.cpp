#include <cstdio>

#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)

#define magic 1000000007

int main() {
  int n; scanf("%d", &n);

  long long f[n+1] = {1,1};
  long long g[n+1] = {0,0,2};

  crep(i, 2, n) {
    f[i] = f[i-1] * i % magic;
  }
  crep(i, 3, n) {
    g[i] = (i*g[i-1]%magic + f[i-1]*2%magic)%magic;
  }
  printf("%lld", g[n]);
  return 0;
}

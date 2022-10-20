#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int mod = 1e9+7, maxN = 1e6+5;
int sqr[maxN], sum[maxN], sqrSum[maxN], memo[maxN];

void init() {
  sqr[0] = sqrSum[0] = memo[0] = 1;
  orep(i, 1, maxN) {
    sqr[i] = sqr[i-1] * 2 % mod;
    sqrSum[i] = (sqrSum[i-1] + sqr[i]) % mod;
    memo[i] = (memo[i-1] + sqr[i]*sqrSum[i]%mod) % mod;
  }
}

int main() {
  int k; scanf("%d", &k);
  init();
  long long ret = 0;
  orep(i, 1, k) {
    const int r = k-i;
    ret = (ret + 
           ((sqr[i] - 1 + mod)%mod
             * ((sqr[r+1]-2+mod)%mod 
                + memo[r-1]) %mod)) % mod;
  }
  printf("%lld", ret);
  return 0;
}

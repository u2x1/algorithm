#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int mod = 1e9+7, maxN = 1e6+5;
long long sqr[maxN], sum[maxN], sqrSum[maxN], memo[maxN], preSum[maxN];

void init() {
  sqr[0] = sqrSum[0] = memo[0] = 1;
  orep(i, 1, maxN) {
    sqr[i] = sqr[i-1] * 2 % mod;  // 2^i 2的i次方
    sqrSum[i] = (sqrSum[i-1] + sqr[i]) % mod;  // 2^0+2^1+...+2^i 公比为2，首项为1的前i项和
    preSum[i] = (sqr[i-1] * (sqr[i]-1)) % mod;  // 1+2+3+..+(2^i-1) 前2^i-1项和
    memo[i] = (memo[i-1] + sqr[i]*sqrSum[i]%mod) % mod; //   2^1 * (1+2^1)  长度为i位的后缀可能的方案数
                                                        // + 2^2 * (1+2^1+2^2)
                                                        // + ...
                                                        // + 2^i * (1+2^1+2^2+...+2^i)
  }
}

int main() {
  int k; scanf("%d", &k);
  init();
  long long ret = 0;
  orep(i, 1, k) {
    const int r = k-i;
    ret = (ret + 
           (preSum[i]
             * ((sqr[r+1]-2+mod) % mod 
                + memo[r-1]) % mod)) % mod;
  }
  printf("%lld", ret);
  return 0;
}

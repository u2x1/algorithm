#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int sqr[2000005], sum[1000005];
const int mod = 1e9+7;

int main() {
  int k; scanf("%d", &k);
  const int k2 = 2*k;
  sqr[0] = 1;
  crep(i, 1, k2) {
    sqr[i] = (sqr[i-1]<<1)%mod;
  }
  int ret = 0;
  orep(i, 1, k) {
    int leftsum = (sqr[2*i-1]-sqr[i-1])+mod;
    const int bit = k-i;
    int rightsum =
                    (sqr[bit-1] * ((sqr[bit]-1+mod)%mod));
    ret = (ret + (leftsum%mod * rightsum)%mod) % mod;
    printf("ret: %d", ret); NL; 
  }
  printf("%d", ret);

  return 0;
}

#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define abs(a)       ((a)<0?-(a):(a))
#define min(a,b)     ((a)<(b)?(a):(b))
#define min3(a,b,c)  min(min(a,b),c)
#define max(a,b)     ((a)>(b)?(a):(b))
#define max3(a,b,c)  max(max(a,b),c)
#define HIT          printf("<%s> ln:%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);


int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int arr[n]={};
  long long rst = 0, tmp;
  orep(i, 0, n) {
    scanf("%lld", &tmp);
    rst += tmp*2 + tmp*(i+1);
    arr[i] = tmp;
  }
  int pos = n-1;
  while(pos > -1) {
    while (arr[pos] == 0) { --pos; }
    int m = k;
    rst += (pos+1) * 2;
    while(m > 0 && pos > -1) {
      const int toBeMinus = min(arr[pos], m);
      m -= toBeMinus;
      arr[pos] -= toBeMinus;
      while (arr[pos] == 0) { --pos; }
    }
  }

  printf("%lld", rst);

  return 0;
}

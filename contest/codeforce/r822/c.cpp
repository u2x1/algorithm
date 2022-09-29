#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    long long cost=0;
    int n; scanf("%d", &n);
    char c[n+1]; scanf("%s", c+1);
    crep(i, 1, n) {
      for(int j=i; j<=n; j+=i) {
        if (c[j] == '1') { break; }
        else if (c[j] == '0') { cost+=i; c[j]='2'; }
        else if (c[j] == '2') { continue; }
      }
    }
    printf("%lld\n", cost);
  }


  return 0;
}

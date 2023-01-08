#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define REDIR        freopen("data.in", "r", stdin);

int main() {
  int t;
  scanf("%d", &t);
  int n, m, k;
  while(t--) {
    scanf("%d%d%d", &n, &m, &k);
    long long a = n/k, b = m/k;
    printf("%lld\n", a*b);
  }
  return 0;
}

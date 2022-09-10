#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    unsigned long long n; scanf("%llu", &n);
    if (n == 1) { printf("2\n");}
    else {
      if (n%2 == 0) { printf("-"); }
      printf("%llu\n", n*(n+1));
    }
  }

  return 0;
}

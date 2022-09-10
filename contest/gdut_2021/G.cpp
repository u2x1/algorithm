#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int a; double b; scanf("%d%lf", &a, &b);
    if (1.0/(1.0-b) + a > 100) { printf("YES"); }
    else { printf("NO"); }
    NL;
  }
  return 0;
}

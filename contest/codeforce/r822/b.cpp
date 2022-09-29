#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int t; scanf("%d", &t);

  while(t--) {
    int n; scanf("%d", &n);
    crep(i, 1, n) {
      crep(j, 1, i) {
        if (j==1||j==i) { printf("1 "); }
        else { printf("0 "); }
      } NL;
    }
  }

  return 0;
}

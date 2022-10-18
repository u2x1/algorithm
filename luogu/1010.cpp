#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

void print(int n) {
  if (n == 0) { printf("2(0)"); }
  if (n == 1) { printf("2"); }
  else {
    int stk[15], cnt=0;
    int i = 0;
    while(n) {
      if (n&1) { stk[cnt++] = i; }
      ++i; n>>=1;
    }
    for(int j = cnt-1; j > -1; --j) {
      if (stk[j] > 1) {
        printf("2(");
        print(stk[j]);
        printf(")");
      } else {
        print(stk[j]);
      }
      if (j != 0) { printf("+"); }
    }
  }
}

int main() {
  int n; scanf("%d", &n);
  if (n == 1) { printf("2(0)"); return 0; }
  print(n);
  return 0;
}

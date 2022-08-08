//QQ 1351966042
//ID U2FsdGVkX1
#include <cstdio>

#define orep(i, a, b) for (int i = (a); i <  b; ++i)
#define crep(i, a, b) for (int i = (a); i <= b; ++i)

int read() {
  int x = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x;
}

int main() {
  int t, n;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    int wtf = 0;
    orep(i, 0, n) {
      wtf ^= read();
    }
    printf("%d\n", wtf);
  }
  return 0;
}

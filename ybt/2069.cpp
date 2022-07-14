#include <cstdio>

int main() {
  int a, b, c, d, e;
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  a=a/3; b+=a; e+=a;
  b=b/3; c+=b; a+=b;
  c=c/3; d+=c; b+=c;
  d=d/3; e+=d; c+=d;
  e=e/3; a+=e; d+=e;
  printf("%5d%5d%5d%5d%5d", a, b, c, d, e);
  return 0;
}


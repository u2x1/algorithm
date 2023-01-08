#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)

int main() {
  int t; scanf("%d", &t);
  int a, b;
  while(t--) {
    scanf("%d%d", &a, &b);
    int rst = 0, tmp = a;
    while(tmp/b) { rst += (tmp/=b); }
    printf("%d\n", rst);
  }
  return 0;
}

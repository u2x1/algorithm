#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;

int main() {
  int n; scanf("%d", &n);
  if (n < 16) {
    printf("%d", n); return 0;
  }
  n -= 15;
  int ret = (n/18)*16;
  n %= 18;
  if (n >= 3) {
    ret += n-2;
  } 
  ret += 15;
  printf("%d", ret);
  return 0;
}

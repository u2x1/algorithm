#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

int main() {
  int s, t; scanf("%d%d", &s, &t);
  long long cnt = 0;
  for(int a = 0; a <= s; ++a) {
    for(int b = 0; b <= a; ++b) {
      for(int c = 0; c <= b; ++c) {
        if (a+b+c > s || a*b*c > t) {
          break;
        }
        ++cnt;
      }
    }
  }
  printf("%lld", cnt);
  return 0;
}

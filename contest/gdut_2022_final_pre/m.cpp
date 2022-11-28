#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int a, b; scanf("%d%d", &a, &b);
    if (std::__gcd(a, b) != 1) {
      printf("-1");
    } else {
      const int sum = a+b;
      orep(i, 2, 10000000) {
        if (std::__gcd(sum, i*a)==1) {
          printf("1 %d", i); break;
        }
      }
    }
    NL;
  }
  return 0;
}

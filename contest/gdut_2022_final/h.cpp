#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;

int main() {
  int n; scanf("%d", &n);
  long long tmp; scanf("%lld", &tmp);
  long long odd = std::max(0ll, tmp), even=0ll;
  orep(i, 1, n) {
    scanf("%lld", &tmp);
    even = std::max(odd-tmp, even);
    odd = std::max(even+tmp, odd);
  }
  printf("%lld", std::max(even, odd));
  return 0;
}

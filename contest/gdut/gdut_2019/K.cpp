#include <cstdio>
#include <cmath>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

bool judge(unsigned long long n, unsigned long long target) {
  const unsigned long long n2 = n+1;
  if (n2*n2*n2 - n*n*n >= target) {
    return 1;
  }
  return 0;
}

bool check(unsigned long long n, unsigned long long p) {
  const unsigned long long n2 = n+1;
  return (n2*n2*n2 - n*n*n) == p;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    unsigned long long p; scanf("%llu", &p);
    unsigned long long l = 0, r = sqrt(p)+1, mid = (l+r)>>1;
    while(l < r-1) {
      if (judge(mid, p)) { r=mid; }
      else { l = mid; }
      mid = (l+r) >> 1;
    }
    if (check(l, p) || check(r, p)) { printf("YES"); }
    else { printf("NO"); }
    NL;
  }

  return 0;
}

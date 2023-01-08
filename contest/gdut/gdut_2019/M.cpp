#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  unsigned long long n, k; scanf("%llu%llu", &n, &k);
  char s[n]; scanf("%s", s);
  unsigned long long idx = k % (n*2);
  idx = idx > n ? 2*n-idx 
                : (idx == 0 ? 0 : idx-1);
  putchar(s[idx]);

  return 0;
}

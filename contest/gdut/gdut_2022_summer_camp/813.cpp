#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)

int main() {
  int n; scanf("%d", &n);
  int a[n], b[n];
  orep(i, 0, n) { scanf("%d", a+i); }
  orep(i, 0, n) { scanf("%d", b+i); }

  std::sort(a, a+n); std::sort(b, b+n);

  int l=0, r=0;
  while(r != n) {
    if (b[r] > a[l]) { ++r; ++l; }
    else { ++r; }
  }

  printf("%d", l);

  return 0;
}

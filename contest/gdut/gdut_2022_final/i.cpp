#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];

int main() {
  int n, t; scanf("%d%d", &n, &t);
  orep(i, 0, n) { scanf("%d", arr+i); }
  while(t--) {
    int l, r; scanf("%d%d", &l, &r);
    --l; --r;
    int cnt = 1;
    while(r > l) {
      if (arr[r] >= arr[l]) {++cnt;}
      --r;
    }
    printf("%d", cnt); NL;
  }
  return 0;
}

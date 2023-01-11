#include <cstdio>
#include <algorithm>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 55;
int arr[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    orep(i, 0, n) { scanf("%d", arr+i); }
    if (n == 1) { printf("YES\n%d\n", arr[0]); continue; }
    std::sort(arr, arr+n);
    if (arr[n-1] == arr[n-2]) {
      if (n == 2 || arr[0] == arr[n-1]) { printf("NO\n"); continue; }
      printf("YES\n%d ", arr[0]);
      for(int i = n-1; i > 0; --i) {
        printf("%d ", arr[i]);
      } NL;
    } else {
      printf("YES\n"); NL;
      for(int i = n-1; i > -1; --i) {
        printf("%d ", arr[i]);
      } NL;
    }
  }

  return 0;
}

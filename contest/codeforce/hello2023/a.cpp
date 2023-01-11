#include <cstdio>
#include <climits>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 2e5+5;
bool arr[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d ", &n);
    int l = -1, r = INT_MAX;
    orep(i, 0, n) {
      if (getchar() == 'L') {
        l = i;
        arr[i] = 0;
      } else {
        r = r == INT_MAX ? i : r;
        arr[i] = 1;
      }
    }
    if (!~l || r == INT_MAX) { printf("-1"); NL; continue; }
    if (l > r) { printf("0"); NL; continue; }
    if (l+1 == r) { printf("%d", r); NL; continue; }
  }

  return 0;
}

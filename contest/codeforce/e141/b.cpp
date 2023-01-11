#include <cstdio>
#include <vector>
#include <algorithm>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 55;

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    std::vector arr(n, std::vector<int>(n));
    bool f = 0; int l = 1, r = n*n;
    orep(i, 0, n) {
      orep(j, 0, n) {
        if (f) { arr[i][j] = r--; }
        else { arr[i][j] = l++; }
        f^=1;
      }
      if (i&1) { std::reverse(arr[i].begin(), arr[i].end()); }
    }
    orep(i, 0, n) {
      orep(j, 0, n) {
        printf("%d ", arr[i][j]);
      } NL;
    }
  }

  return 0;
}

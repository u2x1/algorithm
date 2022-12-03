#include <cstdio>
#include <cstring>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 3e5 + 10;
int arr[maxN];
bool reach[maxN];

int main() {
  int t; scanf("%d", &t);
  reach[0] = 1;
  while(t--) {
    int n; scanf("%d", &n);
    orep(i, 0, n) { scanf("%d", arr+i); }
    std::sort(arr, arr+n);
    memset(reach+1, 0, sizeof(bool)*arr[n-1]);
    int ans = n;
    orep(i, 0, n) {
      if (reach[arr[i]]) { ans--; continue; }
      const int bound = arr[n-1] - arr[i];
      for(int j = 0; j <= bound; ++j) {
        reach[j+arr[i]] |= reach[j];
      }
    }
    printf("%d", ans);
    NL;
  }
  return 0;
}

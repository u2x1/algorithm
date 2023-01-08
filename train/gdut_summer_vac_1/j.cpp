#include <cstdio>
#include <algorithm>
#include <climits>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 2e5+5;
int arr[maxN];
int stk[maxN], stkL, stkR;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  int ret = -INT_MAX;
  int l = 0;
  orep(i, 1, n+1) {
    scanf("%d", arr+i);
    arr[i] += arr[i-1];
    while(stkL != stkR && i - stk[stkL] > m) { stkL++; }
    if (stkL != stkR && (arr[stk[stkL]] - arr[l] < 0 || i - l > m)) {
      l = stk[stkL];
    }
    while(stkL != stkR && arr[i] < arr[stk[stkR-1]]) { stkR--; }
    stk[stkR++] = i; 
    ret = std::max(ret, arr[i] - arr[l]);
    // printf("ret: %d l:%d r: %d \nstk: ", ret, l, i);
    // orep(k, stkL, stkR) { printf("%d ", stk[k]); }; NL; NL;
  }

  while(stkL != stkR) {
    l = stk[stkL++];
    if (l == n) { break; }
    ret = std::max(ret, arr[n] - arr[l]);
  }

  printf("%d", ret);

  return 0;
}

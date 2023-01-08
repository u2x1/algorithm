#include <cstdio>

#define NL putchar(10);

const int maxN = 1e6+5;

int arr[maxN], stk[maxN];
int stkL, stkR;

int main() {
  int n, k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) { scanf("%d", arr+i); }

  for (int i = 0; i < n; ++i) {
    if (stkR!=stkL && i - stk[stkL] == k) { stkL++; }
    while(stkR!=stkL && arr[stk[stkR-1]] >= arr[i]) { stkR--; }
    stk[stkR++] = i;
    if (i >= k - 1) { printf("%d ", arr[stk[stkL]]); }
  } NL;

  stkL = stkR = 0;
  for (int i = 0; i < n; ++i) {
    if (stkR!=stkL && i - stk[stkL] == k) { stkL++; }
    while(stkR!=stkL && arr[stk[stkR-1]] <= arr[i]) { stkR--; }
    stk[stkR++] = i;
    if (i >= k - 1) { printf("%d ", arr[stk[stkL]]); }
  } NL;

  return 0;
}

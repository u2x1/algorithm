#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define REDIR        freopen("data.in", "r", stdin);

int main() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  int arr[n]={}, diff[n+1]={};
  int totDiff = 0;
  orep(i, 0, n) { scanf("%d", arr+i); }
  orep(i, 1, n) { diff[i] = arr[i] - arr[i-1]; totDiff += diff[i]; }

  std::sort(diff, diff+n+1);
  ++totDiff;
  for(int i = n; i > n-k+1; --i) {
    totDiff -= diff[i]-1;
  }

  printf("%d", totDiff);

  return 0;
}

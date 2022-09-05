#include <cstdio>
#include <cstring>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define REDIR        freopen("data.in", "r", stdin);

int n, m, init;

const int steps(const int cur, const int target) {
  if (cur > target) {
    return m-(cur-target);
  } else {
    return target-cur;
  }
}

int cal(const int v, int *arr, int *dist) {
  int rst = 0;
  // printf("%d selected, ", v);
  crep(i, 2, n) {
    rst += std::min(dist[i], 1+steps(v, arr[i]));
  //  printf("%d ", dp[i]);
  }
  // NL;
  return rst;
}

int main() {
  scanf("%d%d", &n, &m);
  int arr[n+1], dist[n+1];
  scanf("%d", arr+1);
  crep(i, 2, n) { scanf("%d", arr+i); dist[i] = steps(arr[i-1], arr[i]); }
  int mmin = 0x3f;
  crep(i, 1, m) {
    mmin = std::min(mmin, cal(i, arr, dist));
  }
  printf("%d", mmin);
  return 0;
}

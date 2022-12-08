#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 5e3+5;
int arr[maxN];

struct st{ int a,b; } sts[maxN];
int dp[maxN];
bool cmp(const st a, const st b) {
  return (a.a == b.a ? a.b < b.b : a.a < b.a);
}

int main() {
  int ret = 0;
  int n; scanf("%d", &n);
  orep(i, 0, n) {
    scanf("%d%d", &sts[i].a, &sts[i].b);
  }
  std::sort(sts, sts+n, cmp);
  orep(i, 0, n) {
    dp[i] = 1;
    orep(j, 0, i) {
      if (sts[j].b > sts[i].b) { dp[i] = std::max(dp[i], dp[j]+1); }
    }
    ret = std::max(ret, dp[i]);
  }
  printf("%d", ret);
  return 0;
}

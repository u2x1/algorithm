#include <cstdio>
#include <cstring>
#include <vector>

#define NL putchar(10);

const int maxN = 1e5+5;

int cost[maxN], test[maxN];
int n, m; 

bool judge(int x) {
  int cnt = m, rest = x;
  std::vector<bool> used(m+1, 0);
  while(cnt && x) {
    if (rest > x) { rest = x; }
    if (test[x] && !used[test[x]]) {
      if (rest < cost[test[x]]+1) { return 0; }
      used[test[x]] = 1;
      --cnt;
      rest -= 1+cost[test[x]];
    }
    --x;
  }
  return !cnt;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", test+i+1);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", cost+i+1);
  }

  int l = 0, r = n+1, mid;
  while(l < r-1) {
    mid = (l+r) / 2;
    if (judge(mid)) { r = mid; }
    else { l = mid; }
  }

  printf("%d", r == n+1 ? -1 : r);

  return 0;
}

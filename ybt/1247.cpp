#include <cstdio>
#include <algorithm>

int len, n, m;
bool judge(int *ls, int x) {
  int sum = 0;
  int rm = 0;
  for(int i=0; i<n; ++i) {
    sum += ls[i];
    if (sum < x) { ++rm; }
    else { sum = 0; }
  }
//  if (sum != 0 && sum < x) { return false; }
  return rm <= m;
}

int main() {
  scanf("%d%d%d", &len, &n, &m);
  int ls[n+1], a = 0, b;
  for(int i = 0; i < n; ++i) {
    scanf("%d", &b);
    ls[i] = b-a;
    a=b;
  }
  ls[n] = len-(n>0 ? ls[n-1] : 0);
  ++n;

  int l = 1, r = len, mid = (l+r) >> 1;
  while(l<r-1) {
    if (judge(ls, mid)) { l = mid; }
    else { r = mid; }
    mid = (l+r) >> 1;
  }
  if (judge(ls, r)) { printf("%d", r); }
  else { printf("%d", l); }

  return 0;
}

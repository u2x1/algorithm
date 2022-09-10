#include <cstdio>
#include <cstring>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define REDIR        freopen("data.in", "r", stdin);

int getModeCnt(long long *arr, int l, int r) {
  std::sort(arr+l, arr+r);
  int cnt = 1, maxcnt = 0;
  crep(i, l+1, r) {
    if (arr[i-1] == arr[i]) {
      ++cnt;
    } else {
      if (maxcnt < cnt) { maxcnt = cnt; }
      cnt = 1;
    }
  }
  return maxcnt > cnt ? maxcnt : cnt;
}

int main() {
  int n, m; scanf("%d%d", &n, &m);
  int p[n+2]; crep(i, 1, n) { scanf("%d", p+i); }
  int pp[n+2]={};
  int rstpp[n+2]={};
  long long store[n+2]={};
  while(m--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    if (op==1) {
      ++pp[l]; --pp[r+1];
    } else {
      memset(rstpp, 0, sizeof(rstpp));
      crep(i, 1, n) { rstpp[i] = pp[i]; rstpp[i] += rstpp[i-1]; }
      crep(i, l, r) {
        long long out = p[i];
        orep(j, 0, rstpp[i]) {
          out = out*251%996*404*123;
        }
        store[i] = out;
      }
      printf("%d\n", getModeCnt(store, l, r));
    }
  }
  return 0;
}

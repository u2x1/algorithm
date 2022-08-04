#include <cstdio>
#include <cstring>

int main() {
  const int len = 10;
  int start[len]={}, end[len]={}, rst[len]={}, relation[len]={};
  memset(start, 0, sizeof(start));
  memset(end, 0, sizeof(end));
  memset(rst, 0, sizeof(rst));
  memset(relation, 0, sizeof(relation));
  int cnt = 0;
  int l, r;
  while(~scanf("%d%d", &l, &r)) {
    ++start[l]; ++end[r]; relation[r] += r-l+1;
  }
  for(int i = 0; i < len; ++i) {
    cnt += start[i];
    if(cnt == 0) { continue; }
    rst[i] += rst[i-1] + cnt;
    if (end[i]) {
      cnt -= end[i];
      printf("rel %d: %d\n", i, relation[i]);
      rst[i+1] -= relation[i];
    }
  }
  for(int i = 0; i < len && rst[i] >= 0; ++i) {
    printf("%d ", rst[i]);
    rst[i] = rst[i-1] + cnt;
  }
  return 0;
}

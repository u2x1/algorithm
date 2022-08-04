#include <cstdio>



int main() {
  const int len = 10;
  int start[len]={}, end[len]={};
  int cnt = 0;
  int l, r;
  while(~scanf("%d%d", &l, &r)) {
    ++start[l]; ++end[r];
  }
  int rst[len] = {};
  for(int i = 0; i < len; ++i) {
    cnt += start[i];
    cnt -= end[i];
    rst[i] = rst[i-1] + cnt;
  }
  for(int i = 0; i < len; ++i) {
    printf("%d ", rst[i]);
    rst[i] = rst[i-1] + cnt;
  }
  return 0;
}

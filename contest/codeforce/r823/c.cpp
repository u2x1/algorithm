#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int t; scanf("%d ", &t);
  char str[200001]={};
  while(t--) {
    int n=0; int tmp;
    int cnt['9'+1]={}, persist['9'+1]={};
    memset(cnt, 0, sizeof(cnt));
    memset(persist, 0, sizeof(persist));
    while((tmp = getchar()) >= '0' && tmp <= '9') {
      ++cnt[tmp];
      crep(i, tmp+1, '9') {
        if (cnt[i]) {
          persist[i=='9'?'9':i+1] += cnt[i];
          cnt[i] = 0;
        }
      }
    }
    crep(i, '0', '9') {
      orep(j, 0, cnt[i]+persist[i]) {
        putchar(i);
      }
    } NL;
    memset(str, 0, n*sizeof(char));
  }

  return 0;
}

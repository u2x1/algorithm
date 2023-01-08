#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

char str[20005], ori[20005];
bool exist[100]; char order[30]; int ordCnt;
int cnt[100], tmpcnt[100];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%s", str); ordCnt = 0;
    memset(exist, 0, sizeof(exist)); 
    memset(cnt, 0, sizeof(cnt)); 
    const int len = strlen(str);
    for(int i = len-1; i>-1; --i) {
      const char c = str[i];
      if (exist[c]) { continue; }
      exist[c] = 1;
      order[ordCnt++] = c;
      ++cnt[c];
    }
    int round = 0, pos = 0;
    for(int i = ordCnt-1; i>-1; --i) {
      const char c = order[i];
      const int tmp = cnt[c] / (i+1);
      if (tmp * (i+1) != cnt[c]) { printf("-1"); goto exit; }
      cnt[c] = tmp;
    }
    while(round != ordCnt && pos != len) {
      memcpy(tmpcnt, cnt, sizeof(cnt));
      while(pos != len) {
        const char c = str[pos];
        if (!cnt[c]) { printf("-1"); goto exit; }
        cnt[c]--;
        ++pos;

      }
    }
    exit:
  }


  return 0;
}

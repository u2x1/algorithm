#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int maxN = 2e5+5;
char tmpStr[maxN];
int mags[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    scanf("%s", tmpStr+1);
    crep(i, 1, n) { scanf("%d", mags+i); }
    const int len = strlen(tmpStr+1)+1;
    tmpStr[0] = tmpStr[len] = '0';
    int startPos = -1; int cnt = 0;
    int sum = 0;
    crep(i, 0, len) {
      if (tmpStr[i] == '1') {
        if (startPos == -1) { startPos = i; }
        ++cnt;
        sum += mags[i];
      }
      else {
        if (cnt > 1 && startPos) {
          const int l = mags[startPos-1];
          int innerMin = INT_MAX;
          orep(j, startPos, i) {
            innerMin = std::min(innerMin, mags[j]);
          }
          sum += innerMin < l ? l - innerMin : 0;
        }
        cnt = 0; startPos = -1;
      }
    }
    printf("%d", sum); NL;
  }


  return 0;
}

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

inline int read() {
  int x=0; char c=0;
  while(c<'0'  || c>'9') {c=getchar();}
  while(c>='0' && c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

const int maxN = 1e5+5;
int n;

struct Et { int dis; int val; } ets[maxN];
bool cmp(const Et &a, const Et &b) {
  return a.dis < b.dis;
}

int main() {
  n = read();
  std::priority_queue<int> lefts;
  orep(i, 0, n) { ets[i].dis = read() * 2; }
  orep(i, 0, n) { ets[i].val = read(); }
  std::sort(ets, ets+n, cmp);
  int curDis = 0, starter = 0;
  int ret = 0, maxPos = -1, tmpVal = -1;
  orep(i, 0, n) {
    const int ntop = lefts.size() ? lefts.top() : -1;
    if (!~maxPos) {
      orep(j, starter, n) {
        if (tmpVal < ets[j].val+ets[j].dis-curDis) {
          tmpVal = ets[j].val+ets[j].dis-curDis;
          maxPos = j;
        }
      }
    }
    if (ntop < tmpVal) {
      curDis = ets[maxPos].dis;
      ret += tmpVal;
      orep(j, starter, n) {
        if (j == maxPos) { continue; }
        if (ets[j].dis > curDis) { starter = j; break; }
        lefts.push(ets[j].val);
      }
      if (curDis == ets[n-1].dis) { starter = n; }
      maxPos = tmpVal = -1;
    } else {
      ret += ntop;
      lefts.pop();
    }
    printf("%d", ret); NL;
  }
  return 0;
}

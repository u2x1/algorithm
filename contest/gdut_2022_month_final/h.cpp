#include <cstdio>
#include <cstring>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int op[6], ed[6];
int tar[6], acu[6];
int seg[11];

int main() {
  int t; scanf("%d", &t);
   while(t--) {
    memset(acu, 0, sizeof(acu));
    orep(i, 0, 5) {
      scanf("%d", tar+i);
      tar[i] *= 60;
    }
    orep(iii, 0, 3) {
      orep(i, 0, 5) {
        scanf("%d%d", op+i, ed+i);
        seg[i] = op[i];
        seg[i+5] = ed[i];
      }
      std::sort(seg, seg+10);
      orep(i, 1, 10) {
        int cnt = 0;
        orep(j, 0, 5) {
          if (op[j] <= seg[i-1] && ed[j] >= seg[i]) {
            ++cnt;
          }
        }
        if (cnt < 3) { continue; }
        orep(j, 0, 5) {
          if (op[j] <= seg[i-1] && ed[j] >= seg[i]) {
            acu[j] += seg[i] - seg[i-1];
          }
        }
      }
    }
    bool flag = 1;
    orep(i, 0, 5) {
      if (acu[i] < tar[i]) {
        flag = 0; break;
      }
    }
    printf(flag ? "xiuwa~xiuwa" : "cai cai ToT"); NL;
   }

  return 0;
}

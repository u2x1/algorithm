#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define drep(i,a,b)  for(auto i=(b); i>=(a); --i)
#define NL           putchar(10);

const int maxN = 1e4+10;
int a[maxN], b[maxN];
bool reach[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n, m; scanf("%d%d", &n, &m);
    orep(i, 0, n) {
      scanf("%d%d", &a[i], &b[i]);
    }
    memset(reach, 0, sizeof(reach));
    reach[0] = 1;
    orep(i, 0, n) {
      const int aa = a[i], bb = b[i];
      drep(j, 0, m) {
        if (!reach[j]) { continue; }
        if (aa > m || bb > m) { continue; }
        reach[aa+j] = 1;
        reach[bb+j] = 1;
      }
    }
    printf((m && reach[m]) ? "Yes" : "No"); NL;
  }
  return 0;
}

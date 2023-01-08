#include <cstdio>
#include <algorithm>
#include <queue>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

struct Range { int l; int r; };
bool operator<(const Range& a, const Range& b) {
  if (a.l == b.l) { return a.r < b.r; }
  return a.l < b.l;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    Range rs[m];
    int maxl = -1, minr = 0x3f3f3f;
    orep(i, 0, m) {
      scanf("%d%d", &rs[i].l, &rs[i].r); --rs[i].l;
      maxl = std::max(maxl, rs[i].l);
      minr = std::min(minr, rs[i].r);
    }
    std::sort(rs, rs+m);
    int minRst = 0x3f3f3f;
    if (k == 1) {
      orep(i, 0, m) {
        minRst = std::min(minRst, rs[i].r-rs[i].l);
      }
    } else {
      minRst = std::max(0, minr-maxl);
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    orep(i, 0, k) { q.push(rs[i].r); }
    int maxLen = q.top()-rs[k-1].l;
    orep(i, k, m) {
      q.push(rs[i].r); q.pop();
      maxLen = std::max(q.top()-rs[i].l, maxLen);
    }
    printf("%d %d\n", minRst, maxLen);
  }
  return 0;
}

#include <cstdio>
#include <queue>
#include <vector>

#define NL putchar(10);

#define maxN 200005

std::vector<int> a[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    int tmp; bool exit = 0;
    std::vector<int> p(n+1, -1), q(n+1, -1);
    std::vector<bool> pUse(n+2, false), qUse(n+2, false);
    std::queue<int> pp, qq;
    int pMax = n, qMax = n;
    for(int i = 1; i<=n; ++i) { a[i].clear(); }
    for(int i = 0; i<n; ++i) { scanf("%d", &tmp); exit = exit ? 1 : tmp > n; a[tmp].push_back(i); }
    if (exit) { printf("NO"); NL; goto fend; }
    for(int i = n; i > 0; --i) {
      if (a[i].size() > 2) {
        printf("NO"); NL; goto fend;
      } else if (a[i].size() == 2) {
        p[a[i][0]] = i; q[a[i][1]] = i;
        pp.push(a[i][1]); qq.push(a[i][0]);
        pUse[i] = qUse[i] = 1;
      } else if (a[i].size() == 1) {
        p[a[i][0]] = q[a[i][0]] =i;
        pUse[i] = qUse[i] = 1;
      }
    }

    while(!pp.empty()) {
      const int pi = pp.front(); pp.pop();
      pMax = pMax > q[pi] ? q[pi] : pMax;
      while(pMax && pUse[pMax]) { --pMax; }
      if (!pMax) { printf("NO"); NL; goto fend; }
      p[pi] = pMax--;
    }
    while(!qq.empty()) {
      const int qi = qq.front(); qq.pop();
      qMax = qMax > p[qi] ? p[qi] : qMax;
      while(qMax && qUse[qMax]) { --qMax; }
      if (!qMax) { printf("NO"); NL; goto fend; }
      q[qi] = qMax--;
    }

    if (qUse[0] || pUse[0]) { printf("NO"); NL; goto fend; }
    printf("YES"); NL;
    for(int i = 0; i < n; ++i) {
      printf("%d ", p[i]);
    } NL;
    for(int i = 0; i < n; ++i) {
      printf("%d ", q[i]);
    } NL;
    fend:;
  }

  return 0;
}

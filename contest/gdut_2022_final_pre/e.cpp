#include <cstdio>
#include <queue>

#define orep(i,a,b)  for(auto i=(a); i<(b); ++i)
#define NL           putchar(10);

const int maxN = 1e6;
int arr[maxN];
bool vis[maxN];
struct st{int id, t;};
std::queue<st> stq;
int querys[maxN], qCnt;

int main() {
  int n; scanf("%d", &n);
  while(n--) {
    int q, t; scanf("%d%d", &q, &t);
    if (q==1) {
      int id; scanf("%d", &id);
      if (!vis[id]) { stq.push({id, t}); }
      vis[id] = !vis[id];
    } else {
      querys[qCnt++] = t;
    }
  }
  int cnt = 0;
  orep(i, 0, qCnt) {
    const int qt = querys[i];
    bool flag = 0;
    while(stq.size()) {
      if (stq.front().t > qt) {
        printf("%d", cnt); NL; flag = 1; break;
      } else {
        ++cnt;
      }
      stq.pop();
    }
    if (!flag) { printf("%d", cnt); NL; }
  }
  printf("%d", cnt+stq.size());
  return 0;
}

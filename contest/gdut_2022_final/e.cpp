#include <cstdio>
#include <queue>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
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
    while(stq.size()) {
      int t = stq.front().t;
      if (t > qt) {
        printf("%d", cnt); NL;
        break;
      } else {
        ++cnt;
      }
      stq.pop();
    }
  }
  printf("%d", cnt+stq.size());
  return 0;
}

#include <cstdio>
#include <set>
#include <map>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e7+5;
std::set<int> boat;
std::map<int, int> cnt;
bool vis[100000];
int tot;

void mod(int t, int i) {
  if (cnt.find(t) == cnt.cend()) {
    cnt[t] = cnt.rbegin()->second + i;
  } else {
    cnt[t] += i;
  }
}

int main() {
  cnt[0] = 0;
  int n; scanf("%d", &n);
  while(n--) {
    int q; scanf("%d", &q);
    if(q == 1) {
      int t, b;
      scanf("%d%d", &t, &b);
      tot += !vis[b]; vis[b] = !vis[b];
      if (boat.find(b) != boat.cend()) {
        mod(t, -1);
        boat.erase(b);
      }
      else {
        mod(t, +1);
        boat.insert(b);
      }
    } else {
      int t; scanf("%d", &t);
      auto up = cnt.upper_bound(t);
      if (up == cnt.cbegin()) {
        printf("0");
      } else if (up == cnt.cend()) {
        printf("%d %d", cnt.crbegin()->first, cnt.crbegin()->second);
      } else {
        printf("%d", (--up)->second);
      }
      NL;
    }
  }
  printf("%d", tot);

  return 0;
}

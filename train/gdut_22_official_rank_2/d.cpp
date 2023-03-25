#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

inline int read() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

const int maxN = 1e6+5;
int a[maxN];
std::vector<int> son[maxN];
int dp1[maxN], dp2[maxN];

int INF = 0x3f3f3f3f;
int ret1, ret2;

void init(int u, int fa) {
  dp1[u] = dp2[u] = -INF;
  if (a[u] == 1) { dp1[u] = 1; }
  if (a[u] == 2) { dp2[u] = 1; }
  orep(it, son[u].cbegin(), son[u].cend()) {
    int v = *it;
    if (v == fa) { continue; }
    init(v, u);
    ret1 = std::max(ret1, dp1[u]+dp1[v]);
    ret2 = std::max(ret2, std::max(dp2[u]+dp1[v], dp1[u]+dp2[v]));
    if (a[u] == 1) {
      dp1[u] = std::max(dp1[u], dp1[v]+1);
      dp2[u] = std::max(dp2[u], dp2[v]+1);
    } else if (a[u] == 2) {
      dp2[u] = std::max(dp2[u], dp1[v]+1);
    }
  }
  ret1 = std::max(ret1, dp1[u]);
  ret2 = std::max(ret2, dp2[u]);
}

int main() {
  int n = read();
  orep(i, 1, n) {
    int aa = read(), bb = read();
    son[aa].push_back(bb);
    son[bb].push_back(aa);
  }
  int mi = INT_MAX;
  orep(i, 1, n+1) {
    a[i] = read();
    if (!a[i]) { printf("0/1"); return 0; }
    mi = std::min(mi, a[i]);
  }

  init(1, 0);
  if (ret1) {
    if (ret2 && (2*ret1) < (1*ret2)) {
      if (!(ret2 & 1)) {
        printf("1/%d", ret2/2); return 0;
      }
      printf("2/%d", ret2); return 0;
    }
    printf("1/%d", ret1); return 0;
  } else {
    printf("%d/1", mi); return 0;
  }

  return 0;
}

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

inline int read() {
  int x=0;char c=0;
  while(c<'0'||c>'9'){c=getchar();} while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
  return x;
}

const int maxN = 1e5+5;
struct st { int l, r; } range[maxN];
bool operator<(const st &a, const st &b) {
  if (a.r == b.r) { return a.l < b.l; }
  return a.r < b.r;
}

int main() {
  int t = read();
  while(t--) {
    int n = read(), m = read(), q = read();
    std::vector<bool> arr(m+1, 0); memset(range, -1, sizeof(range));
    orep(i, 0, n) {
      int a = read(), b = read();
      orep(j, a, b+1) { arr[j] = 1; }
    }
    orep(i, 1, m+1) {
      while(arr[i] > 0 && i <= m) { i++; };
      int l = i;
      while(arr[i] == 0 && i <= m) { i++; };
      int r = --i;
      const int len = r-l+1;
      st cur = { l, r };

      if (range[len] < cur) {
        range[len] = cur;
      }
    }
    st mx = {-1, -1};
    for (int i = m; i > -1; --i) {
      if (range[i] < mx) {
        range[i] = mx;
      } else {
        mx = range[i];
      }
    }

    orep(i, 0, q) {
      int k = read();
      if (range[k].r == -1) { printf("-1 -1\n"); }
      else { printf("%d %d\n", range[k].r-k+1, range[k].r); }
    }
  }

  return 0;
}

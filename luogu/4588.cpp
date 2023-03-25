#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
int f[maxN];

int M;

void pushup(const int p) { f[p] = (1ll*f[p*2]*f[p*2+1])%M; }

void mod(const int pos, const int val, const int p, const int l, const int r) {
  if (l == pos && r == pos) { f[p] = val; return; }
  const int m = (l+r)>>1;
  if (pos <= m) { mod(pos, val, p*2, l, m); }
  if (pos > m) { mod(pos, val, p*2+1, m+1, r); }
  pushup(p);
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 0, maxN) { f[i] = 1; }
  int T; std::cin >> T;
  while(T--) {
    int q; std::cin >> q >> M;
    orep(i, 0, maxN) { f[i] = 1; }
    orep(i, 1, q+1) {
      int a, b; std::cin >> a >> b;
      if (a == 1) { mod(i, b, 1, 0, q); }
      if (a == 2) { mod(b, 1, 1, 0, q); }
      std::cout << f[1]; NL;
    }
  }

  return 0;
}

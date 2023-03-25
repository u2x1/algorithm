#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int f[maxN];

void pushup(const int p) {
  f[p] = std::max(f[p*2], f[p*2+1]);
}

int get(const int l, const int r, const int cl, const int cr, const int p) {
  if (l <= cl && cr <= r) { return f[p]; }
  int ret = 0;
  const int m = (cl+cr) >> 1;
  if (l <= m) { ret = std::max(ret, get(l, r, cl, m, p*2)); }
  if (r > m) { ret = std::max(ret, get(l, r, m+1, cr, p*2+1)); }
  return ret;
}

void mod(const int pos, const int val, const int l, const int r, const int p) {
  if (l == pos && r == pos) { f[p] = val; return; }
  const int m = (l+r)>>1;
  if (l <= m) { mod(pos, val, l, m, p*2); }
  if (r > m)  { mod(pos, val, m+1, r, p*2+1); }
  pushup(p);
}

void build(const int l, const int r, const int p) {
  if (l == r) { f[p] = arr[l]; return; }
  const int m = (l+r)>>1;
  build(l, m, p*2);
  build(m+1, r, p*2+1);
  pushup(p);
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  orep(i, 0, n) {
    std::cin >> arr[i];
  }
  build(0, n-1, 1);
  orep(i, 0, m) {
    int l, r; std::cin >> l >> r; --l; --r;
    std::cout << get(l, r, 0, n-1, 1); NL;
  }

  return 0;
}

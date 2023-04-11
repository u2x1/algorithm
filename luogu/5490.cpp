#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e6+5;
struct query { long long y, x1, x2; bool op; } q[maxN];
bool operator<(const query a, const query b) { return a.y < b.y; }

struct node { long long l, r, val; } t[maxN];
int cnt[maxN];

void pushup(const int p) {
  if (cnt[p]) {
    t[p].val = t[p].r-t[p].l;
  } else {
    t[p].val = t[p*2].val + t[p*2+1].val;
  }
}

std::vector<int> disX;
void build(const int p=1, const int l=0, const int r=disX.size()-1) {
  t[p].l = disX[l];
  t[p].r = disX[r];
  if (l < r-1) {
    const int m = (l+r)/2;
    build(p*2, l, m); build(p*2+1, m, r);
    pushup(p);
  }
}

void update(const int p, const long long x1, const long long x2, bool f) {
  if (t[p].l == x1 && t[p].r == x2) {
    cnt[p] += (f ? 1 : -1);
  } else {
    if (t[p*2].r > x1)   { update(p*2,   x1, std::min(t[p*2].r, x2), f); }
    if (t[p*2+1].l < x2) { update(p*2+1, std::max(x1, t[p*2+1].l), x2, f); }
  }
  pushup(p);
}


signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    int x1, x2, y1, y2; std::cin >> x1 >> y1 >> x2 >> y2;
    disX.emplace_back(x1); disX.emplace_back(x2);
    q[i*2]   = { y1, x1, x2, 1 };
    q[i*2+1] = { y2, x1, x2, 0 };
  }
  std::sort(q, q+n*2);
  std::sort(disX.begin(), disX.end());
  disX.erase(std::unique(disX.begin(), disX.end()), disX.end());
  build();

  update(1, q[0].x1, q[0].x2, q[0].op);
  long long ret = 0;
  orep(i, 1, 2*n) {
    ret += (q[i].y - q[i-1].y) * t[1].val;
    update(1, q[i].x1, q[i].x2, q[i].op);
  }
  std::cout << ret;

  return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
int arr[maxN];
int cpos[maxN];
int pre[maxN];
struct line { int x, lo, hi; int f; };
bool operator<(const line a, const line b) { return a.x < b.x; }
struct query { int x, y, idx; } qs[maxN];
bool operator<(const query a, const query b) { return a.x < b.x; }

//////////////////////// TREE
int t[maxN*4], lz[maxN*4];

void pushup(const int p) { t[p] = t[p*2]+t[p*2+1]; }
void pushdn(const int p) { t[p] += lz[p]; lz[p*2] += lz[p]; lz[p*2+1] += lz[p]; lz[p] = 0; }

int sum(const int pos, const int cl=0, const int cr=maxN, const int p=1) {
  if (pos == cl && cr == pos) { return t[p]+lz[p]; }
  const int m = (cl+cr) >> 1;
  int ret = 0;
  pushdn(p);
  if (pos <= m) { ret += sum(pos, cl, m, p*2); }
  if (pos > m) { ret += sum(pos, m+1, cr, p*2+1); }
  pushup(p);
  return ret;
}

void add(const int val, const int l, const int r, const int cl=0, const int cr=maxN, const int p=1) {
  if (l <= cl && cr <= r) {
    lz[p] += val; return;
  }
  const int m = (cl+cr) >> 1;
  pushdn(p);
  if (l <= m) { add(val, l, r, cl, m, p*2); }
  if (r > m) { add(val, l, r, m+1, cr, p*2+1); }
  pushup(p);
}

//////////////////////// TREE

int ret[maxN];
int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  int tmp;
  memset(cpos, -1, sizeof cpos);
  std::vector<line> v;
  orep(i, 1, n+1) {
    std::cin >> tmp;
    pre[i] = cpos[tmp];
    cpos[tmp] = i;
    v.push_back({pre[i]+1,   i, n, 1});
    v.push_back({i+1,        i, n, -1});
    // std::cout << pre[i]+1 << ',' << i << "  " << i << ',' << n; NL;
  }
  int q; std::cin >> q;
  orep(i, 0, q) { std::cin >> qs[i].x >> qs[i].y; qs[i].idx = i; }
  std::sort(qs, qs+q);
  std::sort(v.begin(), v.end());

  auto vit = v.begin();
  orep(i, 0, q) {
    while (vit != v.end() && vit->x <= qs[i].x) {
      const auto &x = *vit;
      add(x.f, x.lo, x.hi);
      // std::cout << "adding " << x.f << " to " << x.lo << ',' << x.hi << " at " << x.x; NL;
      ++vit;
      // orep(i, 0, 10) { std::cout << sum(i) << " "; } NL;
    }
    ret[qs[i].idx] = sum(qs[i].y);
    // std::cout << "sum of " << qs[i].x << ',' << qs[i].y << " is " << ret[qs[i].idx]; NL;
  }
  orep(i, 0, q) {
    std::cout << ret[i]; NL;
  }

  return 0;
}

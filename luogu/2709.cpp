#include <iostream>
#include <cmath>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 5e4+5;
long long cnt[maxN], c[maxN], ret[maxN];

int N;
struct st { int idx, l, r; } qs[maxN];
bool operator<(const st &a, const st &b) { return a.l/N == b.l/N ? a.r < b.r : a.l/N < b.l/N; }

long long cur = 0;
void add(const int x) { cur += 2*cnt[x]+1; ++cnt[x]; }
void del(const int x) { cur += -2*cnt[x]+1; --cnt[x]; }

int l = 1, r = 2;
long long move(const int a, const int b) {
  while(l < a) { del(c[l++]); }
  while(l > a) { add(c[--l]); }
  while(r < b) { add(c[r++]); }
  while(r > b) { del(c[--r]); }
  return cur;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m, k; std::cin >> n >> m >> k;
  N = pow(n, 0.666);
  orep(i, 1, n+1) { std::cin >> c[i]; }
  orep(i, 0, m) { std::cin >> qs[i].l >> qs[i].r; qs[i].idx = i; }
  std::sort(qs, qs+m);
  add(c[1]);
  orep(i, 0, m) {
    ret[qs[i].idx] = move(qs[i].l, qs[i].r+1);
  }
  orep(i, 0, m) {
    std::cout << ret[i]; NL;
  }

  return 0;
}

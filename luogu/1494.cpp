#include <iostream>
#include <algorithm>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 5e4+5;
long long c[maxN], cnt[maxN]; std::pair<long long, long long> ret[maxN];

int N;
struct st { long long idx, l, r; } qs[maxN];
bool operator<(const st &a, const st &b) { return a.l/N == b.l/N ? a.r < b.r : a.l/N < b.l/N; }

long long cur;
int l = 1, r = 2;
void add(const int x) { cur += ((cnt[x]+1)*cnt[x]-cnt[x]*(cnt[x]-1)); ++cnt[x]; }
void del(const int x) { cur += ((cnt[x]-1)*(cnt[x]-2)-cnt[x]*(cnt[x]-1)); --cnt[x]; }

long long move(const int a, const int b) {
  while(l < a) { del(c[l++]); }
  while(l > a) { add(c[--l]); }
  while(r < b) { add(c[r++]); }
  while(r > b) { del(c[--r]); }
  return cur;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  N = sqrt(n);
  orep(i, 1, n+1) { std::cin >> c[i]; }
  orep(i, 0, m) { std::cin >> qs[i].l >> qs[i].r; qs[i].idx = i; }
  std::sort(qs, qs+m);
  add(c[1]);
  orep(i, 0, m) {
    const long long a = move(qs[i].l, qs[i].r+1);
    if (a && qs[i].l < qs[i].r) {
      const long long b = (qs[i].r-qs[i].l+1) * (qs[i].r-qs[i].l);
      const long long g = std::__gcd(a, b);
      ret[qs[i].idx] = {a/g, b/g};
    } else {
      ret[qs[i].idx] = {0, 1};
    }
  }
  orep(i, 0, m) {
    std::cout << ret[i].first << "/" << ret[i].second; NL;
  }

  return 0;
}

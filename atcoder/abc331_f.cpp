#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

lnt mo = 99998999;

struct BIT {
  int n;
  std::vector<lnt> t;
  BIT (int nn) : n(nn), t(nn) {}
  void add(int p, lnt x) {
    for (++p; p <= n; p += p & -p) {
      t[p-1] = (t[p-1] + x) % mo;
    }
  }
  lnt ask(int p) {
    lnt ret = 0;
    for (; p > 0; p -= p & -p) {
      (ret += t[p-1]) %= mo;
    }
    return ret;
  }
};

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, q; std::cin >> n >> q;
  std::string s; std::cin >> s;
  std::vector<lnt> pw(n+1);
  for (int i = 0; i <= n; ++i) {
    pw[i] = i ? pw[i-1] * 232 % mo : 1;
  }
  BIT pos(n), neg(n);
  auto cal = [&](int len, int c) { return pw[len] * c % mo; };
  for (int i = 0; i < n; ++i) {
    pos.add(i, cal(i, s[i]-'a'+1));
    // std::cout << "adding " << cal(i, s[i]-'a'+1) << " to " << i; NL;
    neg.add(i, cal(n-1-i, s[i]-'a'+1));
    // std::cout << "adding " << cal(n-1-i, s[i]-'a'+1) << " to -" << i; NL;
  }
  while (q--) {
    int e; std::cin >> e;
    if (e == 1) {
      int p; std::string x; std::cin >> p >> x;
      --p;
      lnt dtpos = cal(p, x[0] - 'a' + 1) - cal(p, s[p] - 'a' + 1);
      lnt dtneg = cal(n-1-p, x[0] - 'a' + 1) - cal(n-1-p, s[p] - 'a' + 1);
      pos.add(p, dtpos);
      neg.add(p, dtneg);
      // lnt a = 0;
      // for (int i = 0; i < n; ++i) { a += pos.ask(i+1) - pos.ask(i); }
      // std::cout << a << " ";
      // lnt b = 0;
      // for (int i = 0; i < n; ++i) { b += neg.ask(i+1) - neg.ask(i); }
      // std::cout << b; NL;
      s[p] = x[0];
    } else {
      int l, r; std::cin >> l >> r;
      --l, --r;
      int mid = l + ((r - l) >> 1);
      int ex = (l != r && (r-l+1) % 2 == 0);
      lnt lhs = (pos.ask(mid+1+ex) - pos.ask(l)) * pw[n-l];
      lnt rhs = (neg.ask(r+1) - neg.ask(mid)) * pw[r+1];
      // std::cout << ((lhs % mo + mo) % mo) << " " << ((rhs % mo + mo) % mo); NL;
      std::cout << (((lhs % mo + mo) % mo) == ((rhs % mo + mo) % mo) ? "Yes" : "No"); NL;
    }
  }

  return 0;
}

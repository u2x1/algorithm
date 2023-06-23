#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

struct Fenwick {
  std::vector<int> v; int n;
  Fenwick(int _n) : v(_n), n(_n) {}
  void add(int p, int x) {
    ++p;
    while(p <= n) {
      v[p-1] = v[p-1] + x;
      p += (p & -p);
    }
  }
  int get(int p) {
    ++p;
    int ret = 0;
    while(p > 0) {
      ret += v[p-1]; p -= p&-p;
    }
    return ret;
  }
  int sum(int l, int r) { return get(r-1) - (l == 0 ? 0 : get(l)); }
};

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q; std::string s; std::cin >> n >> s >> q;
  std::vector<int> raw(26);
  std::vector<Fenwick> v(26, Fenwick(n));
  std::set<int> down;

  for(int i = 0; i < s.size(); ++i) {
    auto x = s[i];
    raw[x-'a']++;
    v[x-'a'].add(i, 1);
    if (i+1 != s.size() && s[i+1] < s[i]) { down.insert(i); }
  }

  auto notRise = [&](int l, int r) {
    --r;
    auto it = down.lower_bound(l);
    return (it != down.end() && *it < r);
  };

  while (q--) {
    int e; std::cin >> e;
    if (e == 1) {
      int p; std::string wtf; std::cin >> p >> wtf; char x = wtf[0]; --p;
      // if (s[p] == x) { continue; }
      --raw[s[p]-'a']; ++raw[x-'a'];
      v[s[p]-'a'].add(p, -1); v[x-'a'].add(p, 1);
      s[p] = x;
      if (p-1 >= 0) {
        if (x < s[p-1]) { down.insert(p-1); }
        else { down.erase(p-1); }
      }
      if (p+1 < s.size()) {
        if (s[p+1] < x) { down.insert(p); }
        else { down.erase(p); }
      }
    } else {
      int l, r; std::cin >> l >> r; --l;
      if(notRise(l, r)) { std::cout << "No"; NL; continue; }
      bool judge = 1;
      orep(c, s[l]-'a'+1, s[r-1]-'a') {
        int x = v[c].sum(l, r), y = raw[c];
        if (x != y)  { judge = 0; break; }
      }
      std::cout << (judge ? "Yes" : "No"); NL;
    }
  }

  return 0;
}

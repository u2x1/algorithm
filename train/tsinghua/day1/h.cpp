#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

signed main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0);
    int n, m; std::cin >> n >> m;
    const int inf = 0x3f3f3f3f;
    auto rpos = std::vector(n+1, std::vector(26, std::vector<int>()));
    auto cpos = std::vector(m+1, std::vector(26, std::vector<int>()));
    std::vector mp(n+1, std::vector(m+1, -1));
    for(int i = 1; i <= n; ++i) {
        std::string s; std::cin >> s;
        for(int j = 1; j <= m; ++j) {
            mp[i][j] = s[j-1]-'a';
            rpos[i][mp[i][j]].push_back(j);
            cpos[j][mp[i][j]].push_back(i);
        }
    }

    auto rv = [&](int x, int y, int c) {
      std::pair<int, int> ret = { inf, -1 };
      auto f = [&](int x, int y, int c) {
        auto &v = rpos[x][c];
        if (v.empty()) { return; }
        auto p1 = std::upper_bound(all(v), y);
        if (p1 != v.end()) { ret = std::min(ret, { std::abs(y-*p1), *p1 }); }
        auto p2 = std::upper_bound(v.rbegin(), v.rend(), y, std::greater<int>());
        if (p2 != v.rend()) {
          ret = std::min(ret, { std::abs(y-*p2), *p2 });
        }
      };
      for(int cc = 0; cc < 26; ++cc) {
        if (cc == c) { continue; }
        f(x, y, cc);
      }
      return ret.first == inf ? 2*inf : ret.second;
    };

    auto cv = [&](int x, int y, int c) {
      std::pair<int, int> ret = { inf, -1 };
      auto f = [&](int x, int y, int c) {
        auto &v = cpos[y][c];
        if (v.empty()) { return; }
        auto p1 = std::upper_bound(all(v), x);
        if (p1 != v.end()) { ret = std::min(ret, { std::abs(x-*p1), *p1 }); }
        auto p2 = std::upper_bound(v.rbegin(), v.rend(), x, std::greater<>());
        if (p2 != v.rend()) { ret = std::min(ret, { std::abs(x-*p2), *p2 }); }
      };
      for(int cc = 0; cc < 26; ++cc) {
        if (cc == c) { continue; }
        f(x, y, cc);
      }
      return ret.first == inf ? 2*inf : ret.second;
    };

    int q; std::cin >> q;
    while(q--) {
        int a, b; std::cin >> a >> b;
        std::pair<int, std::array<int, 4>> ret = {inf, {-1, -1, -1, -1}};
        if (a-1) {
            auto xx = rv(a, b, mp[a-1][b]);
            std::pair<int, std::array<int, 4>> x = { 1+std::abs(xx-b), {a-1, b, a, xx} };
            ret = std::min(ret, x);
        }
        if (a+1 <= n) {
            auto xx = rv(a, b, mp[a+1][b]);
            std::pair<int, std::array<int, 4>> x = { 1+std::abs(xx-b), {a+1, b, a, xx} };
            ret = std::min(ret, x);
        }
        if (b-1) {
            auto xx = cv(a, b, mp[a][b-1]);
            std::pair<int, std::array<int, 4>> x = { 1+std::abs(xx-a), {a, b-1, xx, b} };
            ret = std::min(ret, x);
        }
        if (b+1 <= m) {
            auto xx = cv(a, b, mp[a][b+1]);
            std::pair<int, std::array<int, 4>> x = { 1+std::abs(xx-a), {a, b+1, xx, b} };
            ret = std::min(ret, x);
        }
        auto [x, y, c, d] = ret.second;
        if (ret.first == inf) { std::cout << -1; NL; }
        else { std::cout << x << " " << y << " " << c << " " << d; NL; }
    }

    return 0;
}


#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

const long double eps = 1e-12;

struct Pt {
  long double x, y;
};
Pt operator-(Pt a, Pt b) { return { a.x - b.x, a.y - b.y }; }
Pt operator+(Pt a, Pt b) { return { a.x + b.x, a.y + b.y }; }
Pt operator*(Pt a, long double x) { return { a.x * x, a.y * x }; }
Pt operator/(Pt a, long double x) { return { a.x / x, a.y / x }; }


int sgn(long double x) { return (x < -eps ? -1 : x > eps); }

long double dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }
long double det(Pt a, Pt b) { return a.x * b.y - a.y * b.x; }
long double dis(Pt a, Pt b) { return std::sqrt((b.x - a.x) * (b.x - a.x) + (a.y - b.y) * (a.y - b.y)); }

Pt unit(Pt a) {
  long double d = dis(a, {0, 0});
  if (sgn(d) == 0) { return {0, 0}; }
  return Pt{a.x / d, a.y / d};
}

bool operator==(Pt a, Pt b) { return !sgn(dot(a-b, a-b)); }
bool operator<(Pt a, Pt b) { return a.x == b.x ? a.y < b.y : a.x < b.y; }

bool onleft(Pt &a, Pt &b, Pt &x) { return sgn(det(b-a, x-a)) > 0; }

std::vector<Pt> convexHull(std::vector<Pt> pts) {
  std::sort(all(pts));
  std::vector<Pt> ret;
  for (auto &&p : pts) {
    while (ret.size() > 1
        && !onleft(ret[ret.size()-2], ret[ret.size()-1], p)) {
      ret.pop_back();
    }
    ret.emplace_back(p);
  }
  std::reverse(all(pts));
  auto fix = ret.size();
  for (auto &&p : pts) {
    while (ret.size() > fix
        && !onleft(ret[ret.size()-2], ret[ret.size()-1], p)) {
      ret.pop_back();
    }
    ret.emplace_back(p);
  }
  ret.pop_back();
  if (ret.size() <= 2) { return {}; }
  return ret;
}

struct Line {
  Pt s, t;
  long double dis2pt(Pt x) {
    if (s == t) { return dis(s, x); }
    return std::abs(det(x - s, x - t) / dis(s, t));
  }
  long double has(Pt x) {
    if (s == t) { return sgn(dis(s, x)) == 0; }
    return sgn(det(s - x, t - x)) == 0;
  }
};

struct Segment {
  Pt s, t;
  long double dis2pt(Pt x) {
    if (s == t) { return dis(s, x); }
    if (sgn(dot(s - x, t - s)) * sgn(dot(t - x, t - s)) <= 0) {
      return Line{s,t}.dis2pt(x);
    }
    return std::min(dis(s, x), dis(t, x));
  }
  bool has(Pt x) {
    if (s == t) { return sgn(dis(s, x)) == 0; }
    return sgn(det(s - x, t - x)) == 0 && sgn(dot(s - x, t - x)) >= 0;
  }
};

long double area(Pt a, Pt b, Pt c) {
  return std::abs(det(a - b, a - c));
}

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<char> vis(n);
  int cnt = 0;
  std::vector<Pt> pts(n);
  auto dfs = [&](auto &&self, std::vector<int> &subset, int dep) -> bool {
    if (dep == 3) { return 0; }
    bool flag = 0;
    for (int i = 0; i < (int)subset.size(); ++i) {
      for (int j = 0; j <= i; ++j) {
        Line l { pts[subset[i]], pts[subset[j]] };
        std::vector<int> marked {subset[i]};
        {
          vis[subset[i]] = 1;
          cnt ++;
        }
        if (i != j) {
          vis[subset[j]] = 1;
          marked.emplace_back(subset[j]);
          cnt ++;
        }
        std::vector<int> npts;
        for (int k = 0; k < n; ++k) {
          if (vis[k]) { continue; }
          if (!l.has(pts[k])) { if (npts.size() < 4) { npts.emplace_back(k); } continue; }
          marked.emplace_back(k);
          vis[k] = 1; cnt ++;
        }
        if (cnt == n) { flag = 1; }
        else {
          flag |= self(self, npts, dep+1);
        }
        for (auto x : marked) { cnt -= vis[x]; vis[x] = 0; }
      }
    }
    return flag;
  };
  if (n < 4) { std::cout << "possible"; return 0; }
  for (int i = 0; i < n; ++i) {
    std::cin >> pts[i].x >> pts[i].y;
  }
  std::vector<int> subset {0, 1, 2, 3};
  std::cout << (dfs(dfs, subset, 0) ? "possible" : "impossible");


  return 0;
}

#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

const double eps = 1e-12;

struct Pt {
  double x, y;
};
Pt operator-(Pt a, Pt b) { return { a.x - b.x, a.y - b.y }; }
Pt operator+(Pt a, Pt b) { return { a.x + b.x, a.y + b.y }; }
Pt operator*(Pt a, double x) { return { a.x * x, a.y * x }; }
Pt operator/(Pt a, double x) { return { a.x / x, a.y / x }; }


int sgn(double x) { return (x < -eps ? -1 : x > eps); }

double dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }
double det(Pt a, Pt b) { return a.x * b.y - a.y * b.x; }
double dis(Pt a, Pt b) { return std::sqrt((b.x - a.x) * (b.x - a.x) + (a.y - b.y) * (a.y - b.y)); }

Pt unit(Pt a) {
  double d = dis(a, {0, 0});
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
  double dis2pt(Pt x) {
    if (s == t) { return dis(s, x); }
    return std::abs(det(x - s, x - t) / dis(s, t));
  }
};

struct Segment {
  Pt s, t;
  double dis2pt(Pt x) {
    if (s == t) { return dis(s, x); }
    if (sgn(dot(s - x, t - s)) * sgn(dot(t - x, t - s)) <= 0) {
      return Line{s,t}.dis2pt(x);
    }
    return std::min(dis(s, x), dis(t, x));
  }
};

double area(Pt a, Pt b, Pt c) {
  return std::abs(det(a - b, a - c));
}

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);

  double s; std::cin >> s;
  std::vector<std::tuple<double, int, Pt>> events;

  int n; std::cin >> n;
  double terminal = 0;
  std::vector<Pt> pts(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> pts[i].x >> pts[i].y;
  }

  {
    double cur = 0;

    for (int i = 0; i < n; ++i) {
      auto [x, y] = pts[i];
      cur += dis(pts[i], pts[i-!!i]);
      if (i == n-1) { terminal = cur; break; }
      auto v = unit({pts[i+1].x - x, pts[i+1].y - y});
      events.emplace_back(cur + s, 1, v);
      events.emplace_back(cur, 0, v);
    }
  }

  Pt op {0, 0};
  events.emplace_back(terminal, 0, Pt{});
  std::sort(all(events));

  double last = 0;
  double ret = 1e9;
  std::array<Pt, 2> v{Pt{0, 0}, {0, 0}};
  std::cout << std::fixed << std::setprecision(12);
  for (auto [t, man, nv] : events) { 
    // std::cout << "on " << t << ", man" << man << " " << nv.x << "," << nv.y; NL;
    // std::cout << "v" << 0 << " is " << v[0].x << " " <<  v[0].y; NL;
    // std::cout << "v" << 1 << " is " << v[1].x << " " <<  v[1].y; NL;
    Pt ed = op + (v[0] - v[1]) * (t - last);
    if (t == s) { ret = dis(ed, {0, 0}); }
    else if (t > s) { 
      // std::cout << "op is " << op.x <<  "," << op.y; NL;
      // std::cout << "ed is " << ed.x <<  "," << ed.y; NL;
      // std::cout << "new ret candidate: " << Segment{op, ed}.dis2pt({0, 0}); NL;
      ret = std::min(ret, Segment{op, ed}.dis2pt({0, 0}));
    }
    op = ed;
    // std::cout << "op is " << op.x <<  "," << op.y; NL;
    last = t;
    v[man] = nv;
    if (t == terminal) { break; }
  }
  std::cout << ret;

  return 0;
}

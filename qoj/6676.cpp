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


int sgn(double x) { return (x < -eps ? -1 : x > eps); }

double dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }
double det(Pt a, Pt b) { return a.x * b.y - a.y * b.x; }
double dis(Pt a, Pt b) { return std::sqrt((b.x - a.x) * (b.x - a.x) + (a.y - b.y) * (a.y - b.y)); }

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

double triArea(Pt a, Pt b, Pt c) {
  return std::abs(det(a - b, a - c));
}

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);

  int n, p; std::cin >> n >> p;
  std::vector<Pt> pts(n);
  for (int i = 0; i < n; ++i) {
    double d; std::cin >> d;
    d = (d / 180) * std::numbers::pi;
    pts.emplace_back(cos(d) * 1000, sin(d) * 1000);
  }

  std::priority_queue<double> q;

  double all = 0;

  for (int i = 1; i <= n; ++i) {
    double x = (triArea(pts[i-1], pts[i%n], pts[(i+1)%n]));
    all += x;
    q.emplace(x);
  }

  p = n - p;
  while (p--) {
    double x = q.top(); q.pop();
    all -= x;
  }

  std::cout << std::setprecision(12) << std::fixed << all;


  return 0;
}

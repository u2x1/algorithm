#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define NL          std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

struct Pt {
  double x, y;
  Pt operator-(Pt &a) { return { x - a.x, y - a.y }; }
  auto operator<=>(const Pt &a) const = default;
};

const double eps = 1e-9;

int sgn(double x) { return (x < eps ? -1 : x > eps); }

double dis(Pt a, Pt b) { return std::sqrt((b.x - a.x) * (b.x - a.x) + (a.y - b.y) * (a.y - b.y)); }
double dot(Pt a, Pt b) { return a.x * b.x + a.y * b.y; }
double det(Pt a, Pt b) { return a.x * b.y - a.y * b.x; }
bool onleft(Pt &a, Pt &b, Pt &x) { return sgn(det(b-a, x-a)) > 0; }

std::vector<Pt> convexHull(std::span<Pt> pts) {
  std::vector<Pt> ret;
  for (auto &&p : pts) {
    while (ret.size() > 1
        && !onleft(ret[ret.size()-2], ret[ret.size()-1], p)) {
      ret.pop_back();
    }
    ret.emplace_back(p);
  }
  std::reverse(all(pts));
  int fix = ret.size();
  for (auto &&p : pts) {
    while (ret.size() > fix
        && !onleft(ret[ret.size()-2], ret[ret.size()-1], p)) {
      ret.pop_back();
    }
    ret.emplace_back(p);
  }
  ret.pop_back();
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;

  std::vector<Pt> pts(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> pts[i].x >> pts[i].y;
  }

  std::sort(all(pts));

  auto cvh = convexHull(pts);
  double ret = dis(cvh.back(), cvh.front());
  for (int i = 1; i < cvh.size(); ++i) {
    ret += dis(cvh[i], cvh[i-1]);
  }
  std::cout << std::fixed << std::setprecision(10) << ret;

  return 0;
}

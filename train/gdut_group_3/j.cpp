#include <iostream>
#include <iomanip>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e3+5;
struct st { int x; } pts[maxN];
bool vis[maxN]; int cnt;

void mark(const int x) {
  if (!vis[x]) { cnt++; vis[x] = 1; }
  // std::cout << "marking " << x; NL;
}

bool jump(const st &a, const st &b) {
  const bool same = ((a.x % 360) == (b.x % 360) && a.x != b.x);
  // const int updn = std::min((a.y+b.y)*(a.y+b.y), (360-a.y+360-b.y)*(360-a.y+360-b.y));
  // std::cout << "updn is " << sqrt(updn)/2; NL;
  // const int direct = (a.y-b.y)*(a.y-b.y) + (!rev ? (a.x-b.x)*(a.x-b.x) : (720-(a.x-b.x))*(720-(a.x-b.x)));
  if (same) {
    return true;
//    std::cout << "updn is smaller. ";
//    mark(a.x); mark(b.x);
  } else {
    const int l = std::min(a.x, b.x), r = std::max(a.x, b.x);
    if (r-l+1 < 360) {
      // std::cout << "marking " << l/2-180 <<  " to " << r/2-180; NL;
      orep(i, l, r+1) {
        mark(i);
      }
    } else {
      // std::cout << "marking " << r/2-180 <<  " to " << l/2-180; NL;
      orep(i, r, 720+l+1) {
        mark(i%720);
      }
    }
  }
  return false;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    int x, y; std::cin >> y >> x;
//  if (y == -90 || y == 90) { std::cout << "yes"; return 0; }
    x += 180; y += 90;
    x *= 2; y *= 2;
    pts[i].x = x;
//    std::cout << x  << " " << y; NL;
  }
  pts[n] = pts[0];
  orep(i, 1, n+1) {
    if (jump(pts[i-1], pts[i])) { std::cout << "yes"; return 0; }
  }
  std::cout << (cnt == 720 ? "yes" : "no ");
  std::cout << std::fixed << std::setprecision(1);
  if (cnt != 720) {
    orep(i, 0, 720) {
      if (vis[i]) { continue; }
      std::cout << (i-360)/2.0;
      return 0;
    }
  }

  return 0;
}

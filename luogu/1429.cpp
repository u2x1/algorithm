#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int n; long double ans = 1e9;
struct Pt { long double x; long double y; } pts[200005], tmp[200005];

long double dist(const Pt& a, const Pt& b) {
  const long double x = a.x, y = a.y, x2 = b.x, y2 = b.y;
  const long double xdf = x2-x, ydf = y2-y;
  return std::sqrt(xdf*xdf+ydf*ydf);
}

bool cmpX(const Pt& a, const Pt& b) {
  return a.x < b.x;
}
bool cmpY(const Pt& a, const Pt& b) {
  return a.y < b.y;
}

void solve(const int l, const int r) {
  if (l==r) { return; }
  const int mid = (l+r) >> 1;
  solve(l, mid); solve(mid+1, r);
  int cnt = 0;
  for(int i=l;i<=r;i++) {
    if (std::abs(pts[i].x - pts[mid].x) < ans)
			tmp[cnt++]=pts[i];
  }
  std::sort(tmp, tmp+cnt, cmpY);
	orep(i, 0, cnt)	{
    orep(j, i+1, cnt) {
      if (tmp[j].y - tmp[i].y > ans) { break; }
      ans = std::min(ans, dist(tmp[i], tmp[j]));
    }
  }
}

int main() {
  scanf("%d", &n);
  orep(i, 0, n) {
    scanf("%Lf%Lf", &pts[i].x, &pts[i].y);
  }
  std::sort(pts, pts+n, cmpX);
  solve(0, n-1);
  printf("%.4Lf", ans);
  return 0;
}
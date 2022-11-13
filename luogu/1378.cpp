#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int n, x, y, X, Y, boxSize;
int bx[7], by[7];
double dropR[7];
double dist[7][7];

double distSqr(const int id, const int id2) {
  if (dist[id][id2]) { return dist[id][id2]; }
  const int x = bx[id], y = by[id];
  const int x1 = bx[id2], y1 = by[id2];
  return (dist[id][id2] = dist[id2][id] = std::sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y)));
}

double calR(const int id) {
  const int dx = bx[id], dy = by[id];
  if (!((dx <= x && dx >= X) || (dx >= x && dx <= X) && 
       (dy <= y && dy >= Y) || (dy >= y && dy <= Y))) { return 0; }
  const double boundX = std::min(abs(dx-x), abs(dx-X));
  const double boundY = std::min(abs(dy-y), abs(dy-Y));
  double disMin = INT_MAX;
  orep(i, 0, n) {
    if (i==id || !dropR[i]) { continue; }
    double dist = distSqr(i, id);
    if (dist < dropR[i]) { return 0; }
    // exit if a drop is contained in to anthoer
    disMin = std::min(disMin, dist-dropR[i]);
  }
  return std::min({boundX, boundY, disMin});
}

bool visd[7]; int ret = INT_MAX;
void dfs(const int depth) {
  if (depth == n) {
    double sum = 0;
    orep(i, 0, n) {
      sum += M_PI * dropR[i] * dropR[i];
    }
    ret = std::min(ret, (int)((boxSize - sum) + 0.5));
  }
  orep(i, 0, n) {
    if (visd[i]) { continue; }
    double r = calR(i);
    visd[i] = 1; dropR[i] = r;
    dfs(depth+1);
    visd[i] = 0; dropR[i] = 0;
  }
}

int main() {
  scanf("%d%d%d%d%d", &n, &x, &y, &X, &Y);
  boxSize = abs((X-x) * (Y-y));
  orep(i, 0, n) { scanf("%d%d", bx+i, by+i); }
  dfs(0);
  printf("%d", ret);
  return 0;
}
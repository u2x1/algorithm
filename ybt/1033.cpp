#include <cstdio>
#include <cmath>

int main() {
  double xa, ya, xb, yb;
  scanf("%lf%lf%lf%lf", &xa, &ya, &xb, &yb);
  double dtx = xb - xa;
  double dty = yb - ya;
  printf("%.3f", sqrt(dtx*dtx + dty*dty));
  return 0;
}

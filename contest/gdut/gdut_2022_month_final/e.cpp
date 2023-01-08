/* 精度题，不懂 */

#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

const int maxN = 5e6+10;
long double t[maxN], r[maxN], x[maxN], y[maxN];
long double v, startX, startY;

int main() {
  long long n;
  scanf("%lld", &n);
  orep(i, 0, n) {
    scanf("%Lf%Lf%Lf%Lf", t+i, r+i, x+i, y+i);
  }
  scanf("%Lf%Lf%Lf", &v, &startX, &startY);
  orep(i, 0, n) {
    const double curX = startX + v*t[i];
    const float dis = (curX-x[i]) * (curX-x[i]) + (startY-y[i]) * (startY-y[i]);
    if (dis <= r[i] * r[i]) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
  return 0;
}

#include <cstdio>
#include <cmath>

double lenOfSeg(double x1, double y1, double x2, double y2);
double heron(double a, double b, double c);

int main() {
  double x1, y1, x2, y2, x3, y3;
  scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
  double seg1 = lenOfSeg(x1, y1, x2, y2);
  double seg2 = lenOfSeg(x1, y1, x3, y3);
  double seg3 = lenOfSeg(x2, y2, x3, y3);
  double s = heron(seg1, seg2, seg3);
  printf("%.2f", s);
  return 0;
}

double heron(double a, double b, double c) {
  double s = (a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

double lenOfSeg(double x1, double y1, double x2, double y2) {
  double dtx = x1 - x2;
  double dty = y1 - y2;
  return sqrt(dtx*dtx+dty*dty);
}

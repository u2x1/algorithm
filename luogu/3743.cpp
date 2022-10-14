#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

double n, p;
int energy[100005], speed[100005];
double tmp[100005];

bool judge(double sec) {
  double store = p * sec;
  orep(i, 0, n) {
    tmp[i] = 1.0*energy[i] - sec * speed[i] ;
  }
  orep (i, 0, n) {
    if (tmp[i] >= 0) { continue; }
    if ((store += tmp[i]) < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%lf%lf", &n, &p);
  double costpersec = 0;
  orep(i, 0, n) {
    scanf("%d%d", speed+i, energy+i);
    costpersec += speed[i];
  }
  if (n < 1 || costpersec <= p) { printf("-1"); return 0; }
  double l = 0, r = 1e10, mid = (r+l)/2;
  while(r-l >= 0.00001) {
    mid = (r+l) / 2;
    if (judge(mid)) { l = mid; }
    else { r = mid; }
  }

  printf("%f", mid);

  return 0;
}

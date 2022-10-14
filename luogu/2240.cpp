#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

struct Heap { int weight; int value; double pervalue; } hs[105];
bool operator<(const Heap& a, const Heap& b)
  { return a.pervalue > b.pervalue; }

int main() {
  int n; double t;
  scanf("%d%lf", &n, &t);
  orep(i, 0, n) {
    int w, v;
    scanf("%d%d", &w, &v);
    hs[i] = Heap { w, v, (double)v/w };
  }
  std::sort(hs, hs+n);
  double ret = 0;
  orep(i, 0, n) {
    if (t <= 0) { break; }
    if (hs[i].weight >= t) {
      ret += hs[i].value * (t/hs[i].weight);
      break;
    }
    t -= hs[i].weight;
    ret += hs[i].value;
  }

  printf("%.2f", ret);

  return 0;
}

#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  char topName[21]; int topMoney = 0;
  char cName[21]; int a, b; char c, d; int e;
  int cMoney;
  for (int i = 0; i < n; ++i) {
    scanf("%s%d%d %c %c%d", cName, &a, &b, &c, &d, &e);
    cMoney = 0;
    if (a > 80 && e > 0) { cMoney += 8000; }
    if (a > 85 && b > 80) { cMoney += 4000; }
    if (a > 90) { cMoney += 2000; }
    if (a > 85 && d == 'Y') { cMoney += 1000; }
    if (b > 80 && c == 'Y') { cMoney += 850; }
    if (cMoney > topMoney) { topMoney = cMoney; strcpy(topName, cName); }
    sum += cMoney;
  }

  printf("%s\n%d\n%d", topName, topMoney, sum);


  return 0;
}

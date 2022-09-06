#include <cstdio>

bool isRun(const int i) {
    if (!(i%400)) { return 1; }
    else if ((i%100) && !(i%4)) { return 1; }
    return 0;
}

int daysBtwYear(const int a, const int b) {
  if (b < a) { return 0; }
  int runCnt = 0;
  for(int i = a; i <= b; ++i) {
    if (isRun(i)) { ++runCnt; }
  }
  return (b-a+1)*(281+runCnt);
}

int daysBtwMon(const int y, int m1, int m2) {
  int rst = 0;
  while(m1 <= m2) {
    switch(m1) {
      case 1: rst += 16; break;
      case 2: rst += 8 + (isRun(y) ? 1 : 0); break;
      case 7: rst += 10; break;
      case 8: rst += 3; break;
      case 3: case 5: case 10: case 12:
        rst += 31; break;
      case 4: case 6: case 9: case 11:
        rst += 30; break;
    }
    ++m1;
  }
  return rst;
}

int daysBtwDay(const int m, const int d1, const int d2) {
  if (m > 12 || m < 1) { return 0; }
  if (m==1) {
    if (d1 >= 17) { return 0; }
    if (d2 >= 17) { return 17-d1; }
  } else if (m == 2) {
    if (d2 <= 20) { return 0; }
    if (d1 <= 20) { return d2-20; }
  } else if (m==7) {
    if (d1 >= 11) { return 0; }
    if (d2 >= 11) { return 11-d1; }
  } else if (m == 8) {
    if (d2 <= 28) { return 0; }
    if (d1 <= 28) { return d2-28; }
  }
  return d2 - d1 + 1;
}

int cal(int y1, int m1, int d1, int y2, int m2, int d2) {
    int l = y1*10000+m1*100+d1, r = y2*10000+m2*100+d2;
    if (l > r) {
      int cy=y1, cm=m1, cd=d1;
      y1=y2; m1=m2; d1=d2;
      y2=cy; m2=cm; d2=cd;
    }
    int leftExtra = daysBtwMon(y1, m1, 12) - daysBtwDay(m1, 1, d1);
    int rightExtra = daysBtwMon(y2, 1, m2-1) + daysBtwDay(m2, 1, d2);
    int dbt = daysBtwYear(y1+1, y2-1);
    if (y1==y2) { return 1+rightExtra+leftExtra-(281+isRun(y1)); }
    return 1+dbt+leftExtra+rightExtra;
}

int main() {
//  for(int i = 2019; i < 2023; ++i) {
//    for(int j = 1; j < 13; ++j) {
//      for(int k = 1; k <= 31; ++k) {
//        printf("%d-%d-%d: %d \n", i, j, k, cal(2019, 1, 1, i, j, k));
//      }
//    }
//    putchar(10);
//  }
//  return 0;

  int n;
  scanf("%d", &n);
  while(n--) {
    int y1, m1, d1, y2, m2, d2;
    scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2);
    printf("%d", cal(y1, m1, d1, y2, m2, d2));
  }

  return 0;
}

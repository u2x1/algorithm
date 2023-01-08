#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int v1, v2, t, s, l; scanf("%d%d%d%d%d", &v1, &v2, &t, &s, &l);
  int rabit = 0, turtle = 0, resting = 0;
  int sec = 0;
  while(1) {
    if (turtle == l && rabit == l) {
      printf("D\n%d", sec); return 0;
    }
    else if (rabit == l) {
      printf("R\n%d", sec); return 0;
    }
    if (turtle == l) {
      printf("T\n%d", sec); return 0;
    }
    if (!resting) {
      rabit += v1;
    } else {
      --resting;
    }
    turtle += v2;
    if ((!resting) && (rabit - turtle >= t)) {
      resting += s;
    }
    ++sec;
  }

  return 0;
}

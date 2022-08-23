#include <cstdio>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)
#define crep(i,a,b)  for(int i=(a); i<=(b); ++i)
#define abs(a)       ((a)<0?-(a):(a))
#define min(a,b)     ((a)<(b)?(a):(b))
#define min3(a,b,c)  min(min(a,b),c)
#define max(a,b)     ((a)>(b)?(a):(b))
#define max3(a,b,c)  max(max(a,b),c)
#define HIT          printf("entered <%s> at ln:%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);

#define MAGIC 999068070

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  if ((a >= 103 && b >= 103) || a == b) {
    printf("There is no winner!");
  } else if (a >= 103) {
    printf("b is the winner!");
  } else if (b >= 103) {
    printf("a is the winner!");
  } else {
    long long arst=1, brst=1;
    if (a > b) {
      crep(i, 2, b) {
        brst *= i;
        brst %= MAGIC;
      }
      arst = brst;
      crep(i, b+1, a) {
        arst *= i;
        arst %= MAGIC;
      }
    } else {
      crep(i, 2, a) {
        arst *= i;
        arst %= MAGIC;
      }
      brst = arst;
      crep(i, a+1, b) {
        brst *= i;
        brst %= MAGIC;
      }
    }

    if (arst > brst) {
      printf("a is the winner!");
    } else if (arst < brst) {
      printf("b is the winner!");
    } else {
      printf("There is no winner!");
    }
  }
  return 0;
}

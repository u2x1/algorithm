#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int f() {
  int cnt = 0;
  orep(g, 0, 1) {
    int a[5][2] = {{1,2}, {1,2}, {1,2}, {1,2}, {1,2}};
    orep(i, 0, 5) { printf("(%d, %d) ", a[i][0], a[i][1]); } NL;
    int b[5][2] = {{1,2}, {2,3}};
    orep(i, 0, 5) { printf("(%d, %d) ", b[i][0], b[i][1]); } NL;
    int c[5][2] = {};
    orep(i, 0, 5) { printf("(%d, %d) ", c[i][0], c[i][1]); } NL;
  }
}

int main() {
  orep(i, 0, 10) {
    f(); NL;
  }
  return 0;
}

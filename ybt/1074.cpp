#include <cstdio>
#include <iostream>

int main() {
  int my = 0, moms = 0;
  int budget;
  bool flag = 1;
  for (int i = 1; i < 13 && scanf("%d", &budget); ++i) {
    if (!flag) { continue; }
    my += 300 - budget;
    if (my < 0) { printf("%d", -i); flag = 0; }
    if (my > 100) {
      int given = 100 *  (my / 100);
      moms += given;
      my -= given;
    }
  }
  if (flag) {
    std::cout << my + (moms * 1.2);
    // printf("%f", my + (moms * 1.2));
  }
  return 0;
}

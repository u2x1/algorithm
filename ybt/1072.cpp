#include <cstdio>

int main() {
  int n;
  int amount, worked;
  double oriRate;
  scanf("%d%d%d", &n, &amount, &worked);
  oriRate = 1.0 * worked / amount;
  for (int i = 1; i < n && scanf("%d%d", &amount, &worked); ++i) {
    double dt = 1.0 * worked / amount - oriRate;
    if (dt > 0.05) {
      printf("better\n");
    } else if (dt < -0.05) {
      printf("worse\n");
    } else {
      printf("same\n");
    }
  }
  return 0;
}

#include <cstdio>

int main() {
  int height, width; char c; int fill;
  scanf("%d%d %c %d", &height, &width, &c, &fill);
  for(int i = 1; i <= height; ++i) {
    for (int j = 1; j <= width; ++j) {
      if (i!=1 && i!=height && j!=1 && j!=width) {
        if (!fill) { printf(" "); continue; }
      }
      printf("%c", c); 
    }
    printf("\n");
  }
  return 0;
}

#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int arr[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  int x, y;
  scanf("%d%d", &x, &y);
  --x;--y;

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  int c;
  for (int i = 0; i < 5; ++i) {
    c = arr[x][i];
    arr[x][i] = arr[y][i];
    arr[y][i] = c;
  }

  for (int i = 0; i < 5; i++) {
    printf("%d", arr[i][0]);
    for (int j = 1; j < 5; j++) {
      printf(" %d", arr[i][j]);
    }
    printf("\n");
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}

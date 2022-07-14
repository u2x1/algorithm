#include <cstdio>
#include <cstring>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif
  
  int arr[n][n], x = n-1, y = 0, cnt = 1;
  memset(arr, 0, sizeof(arr));
  arr[y][x] = 1;

  const int size = n*n;
  while (cnt < size) {
    while (y + 1 < n && !arr[y+1][x]) { arr[++y][x] = ++cnt; }
    while (x - 1 > -1 && !arr[y][x-1]) { arr[y][--x] = ++cnt; }
    while (y - 1 > -1 && !arr[y-1][x]) { arr[--y][x] = ++cnt; }
    while (x + 1 < n && !arr[y][x+1]) { arr[y][++x] = ++cnt; }
  }

  for (int i = 0; i < n; ++i) {
    printf("%d", arr[i][0]);
    for (int j = 1; j < n; ++j) {
      printf(" %d", arr[i][j]);
    }
    printf("\n");
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}

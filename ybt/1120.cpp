#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n, i, j;
  scanf("%d%d%d", &n, &i, &j);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  for (int k = 1; k <= n; ++k) {
    printf("(%d,%d) ", i, k);
  }
  printf("\n");
  for (int k = 1; k <= n; ++k) {
    printf("(%d,%d) ", k, j);
  }
  printf("\n");

  int df = i - j;
  if (df < 0) {
    df = -df;
    for (int k = 1+df; k <= n; ++k) {
      printf("(%d,%d) ", k-df, k);
    }
  } else {
    for (int k = 1+df; k <= n; ++k) {
      printf("(%d,%d) ", k, k-df);
    }
  }
  printf("\n");
  
  i = n - (i-1);  df = i - j;
  if (df < 0) {
    df = -df;
    for (int k = 1+df; k <= n; ++k) {
      printf("(%d,%d) ", n+1-(k-df), k);
    }
  } else {
    for (int k = 1+df; k <= n; ++k) {
      printf("(%d,%d) ", n+1-k, k-df);
    }
  }



#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}

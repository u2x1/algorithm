#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  char raw[200];
  int i = 0;
  for (; scanf("%c", &raw[i]) != EOF && raw[i] != '\n'; ++i);
  char a, b;
  scanf("%c %c", &a, &b);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  for (int j = 0; j != i; ++j) {
    if (raw[j] == a) { printf("%c", b); }
    else { printf("%c", raw[j]); }
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}

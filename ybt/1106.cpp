#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  int a = 0, b = 0, c = 0 , d = 0;
  int cache; 
  for (int i = 0; i < n; ++i){
    scanf("%d", &cache);
    if (cache >= 0 && cache <= 18) { ++a; }
    else if (cache >= 19 && cache <= 35) { ++b; }
    else if (cache >= 36 && cache <= 60) { ++c; }
    else if (cache >= 61) { ++d; }
  }

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%"
      , a*100.0/n, b*100.0/n, c*100.0/n, d*100.0/n);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}

#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>
#include <numeric>

struct pep { int id; double time; };

bool operator<(pep a, pep b) {
  if (a.time == b.time) {
    return a.id < b.id;
  } return a.time < b.time;
}

int main() {
  int n;
  scanf("%d", &n);
  pep arr[n+1];
  for(int i = 1; i<=n; ++i) {
    scanf("%lf", &arr[i].time);
    arr[i].id = i;
  }
  std::sort(arr+1, arr+n+1);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  double sum = 0; arr[0].time = 0;
  double lastWait = 0;
  for(int i = 1; i <= n; ++i) {
    printf("%d ", arr[i].id);
    lastWait += arr[i-1].time;
    sum += lastWait;
  } putchar('\n');
  printf("%.2f", sum / n);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
